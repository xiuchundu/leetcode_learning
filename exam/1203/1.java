import java.nio.charset.StandardCharsets;
import java.util.Scanner;
import java.util.List;

public class Main {
    /**
     * 待实现函数copyDir，在此函数中填入答题代码
     *
     * @param targetDir 输入的文件夹信息（字符串数组）
     * @param dstDirLine 复制的目的文件夹在targetDir中的位置，即复制的目的文件夹为targetDir[dstDirLine - 1]
     * @param srcDir 复制的源文件夹信息（字符串数组）
     * @return String[] 「树状格式」输出信息
     */
    private static String[] copyDir(String[] targetDir, int dstDirLine, String[] srcDir) {
        List<Node> targetNode = buildTree(targetDir);
        List<Node> srcNode = buildTree(srcDir);
        if (srcDir.length == 0) {
            return targetDir;
        }
        addDirtoNode(targetNode.get(dstDirLine - 1), srcNode.get(0));
        List<String> outStr = new ArrayList<>();
        finalResult(targetNode.get(0), 0, outStr);
        String[] result = new String[outStr.size()];
        for (int i = 0; i < outStr.size(); i++) {
            result[i] = outStr.get(i);
        }
        return result;
    }

    private static void finalResult(Node node, int floor, List<String> outStr) {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < floor; i++) {
            builder.append("  ");
        }
        if (node != null) {
            outStr.add(builder + node.name);
            for (Node child : node.children) {
                finalResult(child, floor + 1, outStr);
            }
        }
    }

    public static void addDirtoNode(Node node1, Node node2) {
        Map<String, Integer> maps = new HashMap<>();
        for (int i = 0; i < node1.children.size(); i++) {
            maps.put(node1.children.get(i).name, i);
        }

        for (Node child : node2.children) {
            if (!maps.containsKey(child.name)) {
                node1.children.add(child);
            } else {
                addDirtoNode(node1.children.get(maps.get(child.name)), child);
            }
        }

        node1.children.sort(Comparator.comparing(o -> o.name));
    }

    static class Node {
        int level = -1;
        String name = null;
        List<Node> children = null;
        Node(String name, int level) {
            this.name = name;
            this.level = level;
            this.children = new ArrayList<>();
        }

        void addChild(Node child) {
            if (!this.children.contains(child)) {
                this.children.add(child);
            }
        }
        @Override
        public boolean equals(Object obj) {
            if (obj instanceof Node) {
                Node temp = (Node) obj;
                return this.name.equals(temp.name) && (this.level == temp.level) ;
            }
            return false;
        }
        @Override
        public int hashCode() {
            return this.name.hashCode() + this.level;
        }
    }

    /**
     * 根据输入信息完成树的构建，此部分代码可自行决定是否要改动和调用
     *
     * @param strs 输入的文件夹信息（字符串数组）
     * @return List<Node> 完成构建后的树节点列表，首元素为树的根节点
     */
    private static List<Node> buildTree(String[] strs) {
        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < strs.length; i++) {
            int idx = strs[i].lastIndexOf(" ");
            nodes.add(new Node(strs[i].substring(idx + 1), (idx + 1) / 2));
        }
        // 完成子节点挂接
        for (int i = 0; i < nodes.size(); i++) {
            Node cur = nodes.get(i);
            for (int j = i + 1; j < nodes.size(); j++) {
                Node temp = nodes.get(j);
                if (cur.level >= temp.level) {
                    break;
                }
                if (temp.level == cur.level + 1) {
                    cur.addChild(temp);
                }
            }
        }

        return nodes;
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in, StandardCharsets.UTF_8.name());
        String temp[] = cin.nextLine().trim().split(" ");
        int targetDirNum = Integer.parseInt(temp[0]);
        String[] targetDir = new String[targetDirNum];
        for (int i = 0; i < targetDirNum; i++) {
            targetDir[i] = cin.nextLine();
        }
        int srcDirNum = Integer.parseInt(cin.nextLine().trim());
        String[] srcDir = new String[srcDirNum];
        for (int i = 0; i < srcDirNum; i++) {
            srcDir[i] = cin.nextLine();
        }
        cin.close();

        int dstDirLine = Integer.parseInt(temp[1]);
        String[] results = copyDir(targetDir, dstDirLine, srcDir);
        Arrays.stream(results).forEach(System.out::println);
    }
}

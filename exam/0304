    static int[] getNotificationOrder(int mapSideLen, int gridSideLen, Earthquake earthquake, int[][] userArray) {
        int num = mapSideLen / gridSideLen;
        Map<Integer, Integer> map = new HashMap<>();
        for (int[] item : userArray) {
            int gridNum = (item[0] / gridSideLen) * num + item[1] / gridSideLen + 1;
            map.put(gridNum, map.getOrDefault(gridNum, 0) + 1);
        }

        List<int[]> list = new ArrayList<>();
        for(int key : map.keySet()) {
            int gridX = ((key - 1) / num) * gridSideLen + gridSideLen / 2;
            int gridY = ((key - 1) % num) * gridSideLen + gridSideLen / 2;
            int dis = getDis(earthquake, gridX, gridY);
            if (dis <= earthquake.radius) {
                list.add(new int[]{dis, map.get(key), key});
            }
        }

        if (list.size() == 0) {
            return new int[]{};
        }

        list.sort((Comparator<int[]>) (o1, o2) -> {
            if (o1[0] != o2[0]) {
            return o1[0] - o2[0];
            } else {
                if (o2[1] != o1[1]) {
                    return o2[1] - o1[1];
                } else {
                    return o1[2] - o2[2];
                }
            }
        });

        int[] res = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            res[i] = list.get(i)[2];
        }
        return res;
    }

    public static int getDis(Earthquake earthquake, int x, int y) {
        return Math.abs(earthquake.rowIdx - x) + Math.abs(earthquake.colIdx - y);
    }

    static class Earthquake {
        public final int radius;
        public final int rowIdx;
        public final int colIdx;

        Earthquake(int radius, int rowIdx, int colIdx) {
            this.radius = radius;
            this.rowIdx = rowIdx;
            this.colIdx = colIdx;
        }
    }

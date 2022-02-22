class Solution {
    public static List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<cmp> queue = new PriorityQueue<>();
        int l1 = 0, l2 = 0;
        if (nums1.length > k && nums2.length > k) {
            l1 = k;
            l2 = k;
        } else {
            l1 =nums1.length;
            l2 = nums2.length;
        }
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                queue.add(new cmp(nums1[i], nums2[j]));
            }
        }

        List<List<Integer>> res = new ArrayList<>();
        List<Integer> tmp = new ArrayList<>();
        int cnt = 0;
        if (queue.size() <= k) {
            while (queue.size() > 0) {
                tmp.clear();
                cmp cc = queue.poll();
                if (cc != null) {
                    tmp.add(cc.x);
                    tmp.add(cc.y);
                    res.add(new ArrayList<>(tmp));
                    cnt++;
                }
            }
            return res;
        }
        while (cnt < k) {
            tmp.clear();
            cmp cc = queue.poll();
            if (cc != null) {
                tmp.add(cc.x);
                tmp.add(cc.y);
                res.add(new ArrayList<>(tmp));
                cnt++;
            }
        }

        return res;
    }

    public static class cmp implements Comparable<cmp> {
        public cmp(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public void setX(int x) {
            this.x = x;
        }

        public int getY() {
            return y;
        }

        public void setY(int y) {
            this.y = y;
        }

        int x;
        int y;

        @Override
        public int compareTo(cmp o) {
            if ((this.x + this.y) != (o.x + o.y)) {
                return (this.x + this.y) - (o.x + o.y);
            } else {
                if (this.x != o.x) {
                    return this.x - o.x;
                }
                if (this.x == o.x) {
                    return this.y - o.y;
                }
                return this.y - o.y;
            }

        }
    }
}

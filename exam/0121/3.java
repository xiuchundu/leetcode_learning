// 原始题型239 滑动窗口最大值
// 对于本题而言，初始时，我们将数组nums 的前 k 个元素放入优先队列中。每当我们向右移动窗口时，我们就可以把一个新的元素放入优先队列中，此时堆顶的元素就是堆中所有元素的最大值。然而这个最大值可能并不在滑动窗口中，在这种情况下，这个值在数组nums 中的位置出现在滑动窗口左边界的左侧。因此，当我们后续继续向右移动窗口时，这个值就永远不可能出现在滑动窗口中了，我们可以将其永久地从优先队列中移除。

// 我们不断地移除堆顶的元素，直到其确实出现在滑动窗口中。此时，堆顶元素就是滑动窗口中的最大值。为了方便判断堆顶元素与滑动窗口的位置关系，我们可以在优先队列中存储二元组 (num,index)，表示元素num 在数组中的下标为index。

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>(new Comparator<int[]>() {
            public int compare(int[] pair1, int[] pair2) {
                return pair1[0] != pair2[0] ? pair2[0] - pair1[0] : pair2[1] - pair1[1];
            }
        });
        for (int i = 0; i < k; ++i) {
            pq.offer(new int[]{nums[i], i});
        }
        int[] ans = new int[n - k + 1];
        ans[0] = pq.peek()[0];
        for (int i = k; i < n; ++i) {
            pq.offer(new int[]{nums[i], i});
            while (pq.peek()[1] <= i - k) {
                pq.poll();
            }
            ans[i - k + 1] = pq.peek()[0];
        }
        return ans;
    }
}

// 时间复杂度：O(nlogn)，其中 nn 是数组nums 的长度。在最坏情况下，数组 nums 中的元素单调递增，那么最终优先队列中包含了所有元素，没有元素被移除。由于将一个元素放入优先队列的时间复杂度为O(logn)，因此总时间复杂度为O(nlogn)。

// 空间复杂度：O(n)，即为优先队列需要使用的空间。这里所有的空间复杂度分析都不考虑返回的答案需要的O(n) 空间，只计算额外的空间使用。

*************** 变化题型：求每个滑动窗口内的最大值>= 平均值 * num的个数 ************
// 隐藏的小陷阱，求sum的值可能会溢出，sum类型为保留精度，需要使用double类型。
public int numBigList(int[] cal, int size, int num) {
        Queue<Integer> qu = new PriorityQueue<>((o1, o2) -> {
            return o2 - o1;
        });
        int left = 0;
        int right = size;
        double sum = 0;
        int result = 0;
        for (int n = 0; n < size; n++) {
            qu.add(cal[n]);
            sum += cal[n];
        }
        double ave1 = (sum / size);
        if (qu.peek() > ave1 * num) {
            result++;
        }
        while (right < cal.length) {
            qu.add(cal[right]);
            sum += cal[right++];
            qu.remove(cal[left]);
            sum -= cal[left++];
            double ave = (sum / size);
            if (qu.peek() > ave * num) {
                result++;
            }
        }
        return result;
    }

// 进一步优化，上述解法使用了优先级队列，底层实现是堆，add的时间复杂度是O(log(n))，remove的时间复杂度为O(N)，结果会超时。使用Treemap进行优化。
// 而TreeMap 则是基于红黑树的一种提供顺序访问的 Map,和 HashMap 不同,它的 get、put、remove 之类操作都是 O(log(n))的时间复杂度。
    public int numBigList(int[] cal, int size, int num) {
        int left = 0;
        int right = 0;
        Double sum = 0d;
        int ans = 0;
        TreeMap<Integer, Integer> treeMap = new TreeMap<>();

        while (right < cal.length) {
            while (right - left + 1 < size) {
                treeMap.put(cal[right], treeMap.getOrDefault(cal[right], 0) + 1);
                sum += cal[right];
                right++;
            }

            treeMap.put(cal[right], treeMap.getOrDefault(cal[right], 0) + 1);
            sum += cal[right];
            if (Double.valueOf(treeMap.lastKey()) > (sum / size) * num) {
                ans++;
            }

            int nn = treeMap.get(cal[left]);
            if (nn == 1) {
                treeMap.remove(cal[left]);
            } else {
                treeMap.put(cal[left], nn - 1);
            }

            sum = sum - cal[left];

            left++;
            right++;
        }
        return ans;
    }


class Solution {
    int n = 0;
    int ans = 0;
    long maxScore = 0;
    int[] L;
    int[] R;

    public int countHighestScoreNodes(int[] parents) {
        n = parents.length;
        L = new int[n];
        R = new int[n];
        for (int i = 0; i < n; ++i) L[i] = R[i] = -1;
        for (int i = 1; i < n; ++i) {
            int p = parents[i];
            if (L[p] == -1) L[p] = i;
            else R[p] = i;
        }
        dp(0);
        return ans;
    }

    // 自底向上，返回当前子树的节点总数 dp[node] = dp[left] + dp[right] + 1
    int dp(int i) {
        if (i == -1) return 0;
        int a = dp(L[i]), b = dp(R[i]);
        // 左子树 * 右子树 * 父树，如果是空树*1即可
        long score = (long) Math.max(a, 1) * Math.max(b, 1) * Math.max(n - a - b - 1, 1);
        if (score > maxScore) {
            maxScore = score;
            ans = 1;
        } else if (score == maxScore) {
            ++ans;
        }
        return a + b + 1;
    }
}

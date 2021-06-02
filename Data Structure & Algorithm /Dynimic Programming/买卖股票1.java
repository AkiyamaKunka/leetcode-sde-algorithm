class Solution {
    // https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/submissions/

    // basic dp with 2 status
    // f(i) = f(i - 1) / f(i - 1) + today, which means the profit of it.
    // f(0) = 0 
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if(n < 2) return 0;
        int [][] dp = new int[n][2];
        // dp[i][0] 0 means not taking the stock 1 means taking the stock
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < n; ++i){
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = Math.max(dp[i - 1][1], -prices[i]);
        }
        return dp[n - 1][0];
    }
}
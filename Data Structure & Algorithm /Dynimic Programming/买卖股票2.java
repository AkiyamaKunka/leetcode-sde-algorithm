class Solution {
    //https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/
    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        if(n < 2) return 0;
        for(int i = 1; i < n; ++i){
            int dif = prices[i] - prices[i -1];
            if(dif > 0) ans += dif;
        }
        return ans;
    }
};
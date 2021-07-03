class Solution {
    // https://leetcode-cn.com/problems/subarray-sum-equals-k/
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        int [] sum = new int[n];
        int pre = 0;
        for(int i = 0; i < n; ++i){
            sum[i] = pre + nums[i];
            pre = sum[i];
        }
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                if(sum[j] - sum[i] + nums[i] == k) ans++;
            }
        }
        return ans;
    }
}
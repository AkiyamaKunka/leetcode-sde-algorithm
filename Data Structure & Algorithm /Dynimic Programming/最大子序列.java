class Solution {
    // https://leetcode-cn.com/problems/maximum-subarray/submissions
    // rolling array + basic DP
    public int maxaySubArray(int[] nums) {
        int n = nums.length;
        int ans = nums[0];
        int pre = nums[0];
        for(int i = 1; i < n; ++i){
            pre = Math.max(pre + nums[i], nums[i]);
            if(pre > ans) ans = pre;
        }
        return ans;
    }
}
class Solution {
    //https://leetcode-cn.com/problems/two-sum-less-than-k/submissions/
    public int twoSumLessThanK(int[] nums, int k) {
        Arrays.sort(nums);
        int l = 0;
        int r = nums.length - 1;
        int res = -1;
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum < k){
                l++;
                res = Math.max(sum, res);
            }
            else r--;
        }
        return res;
    }
}
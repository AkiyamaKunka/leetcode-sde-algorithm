class Solution {
    // https://leetcode-cn.com/problems/minimum-size-subarray-sum/submissions/
    public int minSubArrayLen(int target, int[] nums) {
        int l = 0;
        int r = 0;
        int ans = 0x3f3f3f3f;
        int sum = nums[0];
        while(r < nums.length){
            if(sum < target){
                r++;
                if(r < nums.length)
                    sum += nums[r];
            }else{
                if(l == r) {
                    ans = 0;
                    r++;
                }
                else{
                    if(r - l < ans) ans = r - l;
                    sum -= nums[l++];
                }
            }
        }
        return ans == 0x3f3f3f3f ? 0 : ans + 1;
    }
}
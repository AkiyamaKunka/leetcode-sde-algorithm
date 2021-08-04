class Solution {
    public int triangleNumber(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int ans = 0;
        for(int r = n - 1; r > 0; r--){
            for(int m = r - 1, l = 0; m > l; m--){
                while(l < m && nums[l] + nums[m] <= nums[r]) l++;
                ans += m - l;
            }
        }
        return ans;
    }
}


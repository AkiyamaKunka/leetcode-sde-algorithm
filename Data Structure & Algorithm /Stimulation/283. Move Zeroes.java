class Solution {
    public void moveZeroes(int[] nums) {
        // https://leetcode-cn.com/problems/move-zeroes/
        int n = nums.length;
        int l = 0;
        int r = 0;
        while(l < n){
            if(nums[l] == 0) break;
            l++;
        }
        while(r < n){
            if(nums[r] != 0 && r > l) break;
            r++;
        }
        while(l < n && r < n && l < r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;

            while(l < n){
                if(nums[l] == 0) break;
                l++;
            }
            while(r < n ){
                if(nums[r] != 0 && r > l) break;
                r++;
            }
        }

    }
}
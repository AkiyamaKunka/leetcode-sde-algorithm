class Solution {
    // https://leetcode-cn.com/problems/sort-colors/
    public void exch(int[] nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    public void sortColors(int[] nums) {
        int n = nums.length;
        int l, r;
        l = -1;
        r = 0;
        for(int num = 0; num < 3; ++num){
            while(r < n){
                if(nums[r] == num){
                    exch(nums, l + 1, r);
                    l++;
                }
                r++;
            }
            r = l + 1;
        }
    }
}
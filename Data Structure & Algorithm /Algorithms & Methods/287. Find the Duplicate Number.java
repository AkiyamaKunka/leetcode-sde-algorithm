class Solution {
    //https://leetcode-cn.com/problems/find-the-duplicate-number/
    public int findDuplicate(int[] nums) {
        int n = nums.length - 1;
        if(n == 1) return nums[0];
        int fast, slow;
        fast = slow = 0;
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(fast != slow);
        int begin = 0;
        while(begin != slow){
            begin = nums[begin];
            slow = nums[slow];
        }
        return begin;
    }
}
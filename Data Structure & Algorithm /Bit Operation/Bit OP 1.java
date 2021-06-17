class Solution {
    //https://leetcode-cn.com/problems/single-number/submissions/
    public int singleNumber(int[] nums) {
        int i = 0;
        for(int a : nums)i ^= a;
        return i;
    }
}


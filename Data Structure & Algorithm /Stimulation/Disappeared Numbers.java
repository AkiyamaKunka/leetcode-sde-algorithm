class Solution {
    // https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
    //
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        List ans = new LinkedList<>();
        for(int i = 0; i < n; ++i){
            nums[(nums[i] - 1) % n] += n;
        }
        for(int i = 0; i < n; ++i){
            if(nums[i] <= n) ans.add(i + 1);
        }
        return ans;
    }
}
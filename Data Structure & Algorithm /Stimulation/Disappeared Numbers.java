class Solution {
    // https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        int [] res = new int[n + 1];
        for(int i = 0; i < n; ++i){
            res[nums[i]] = 1;
        }
        List ans = new LinkedList<>();
        for(int i = 1; i < n + 1; ++i){
            if(res[i] == 0) ans.add(i);
        }
        return ans;
    }
}
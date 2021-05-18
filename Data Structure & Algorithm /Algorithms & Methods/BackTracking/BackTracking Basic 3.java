class Solution {
    //  https://leetcode-cn.com/problems/subsets/submissions/
    LinkedList<Integer> s = new LinkedList<>();
    List<List<Integer>> ans = new LinkedList<>();
    int N;
    void backTracking(int cur, int[] nums){
        if(cur == N){
            ans.add(new LinkedList(s));
            return;
        }
        s.add(nums[cur]);
        backTracking(cur + 1, nums);
        s.removeLast();
        backTracking(cur + 1, nums);

    }
    public List<List<Integer>> subsets(int[] nums) {
        N = nums.length;
        backTracking(0, nums);
        return ans;
    }
}
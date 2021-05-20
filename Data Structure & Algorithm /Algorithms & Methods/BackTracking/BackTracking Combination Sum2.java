class Solution {
    // https://leetcode-cn.com/problems/combination-sum-ii/submissions/
    int N;
    int Target;
    List<List<Integer>> ans = new LinkedList<>();
    void dfs(int sum, int cur, int[] nums, LinkedList<Integer> sub){
        if(sum == Target){
            ans.add(new ArrayList(sub));
            return;
        }
        if(sum > Target) return;
        if(cur >= N) return;
        sub.add(nums[cur]);
        dfs(sum + nums[cur], cur, nums, sub);
        sub.removeLast();
        dfs(sum, cur + 1, nums, sub);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        N = candidates.length;
        Target = target;
        LinkedList<Integer> sub = new LinkedList<>();
        dfs(0, 0, candidates, sub);
        return ans;
    }
}
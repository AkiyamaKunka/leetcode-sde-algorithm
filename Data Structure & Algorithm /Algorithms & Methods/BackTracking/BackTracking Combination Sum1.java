class Solution {
    // https://leetcode-cn.com/problems/combination-sum-ii/submissions/
    List<List<Integer>> ans = new LinkedList<>();
    LinkedList<Integer> t = new LinkedList<>();
    int Target;
    void dfs(boolean pre, int cur, int [] nums, int sum){
        if(sum == Target){
            ans.add(new ArrayList(t));
            return;
        }
        //System.out.println("Sum is " + sum + " and cur is " + cur);
        if(cur >= nums.length || sum > Target) return;

        dfs(false, cur + 1, nums, sum);
        //System.out.println("cur is " + cur);
        if(pre == false && cur > 0 && cur < nums.length && nums[cur] == nums[cur - 1]){
            return;
        }
        //System.out.println("Going to judge!");
        t.add(nums[cur]);
        dfs(true, cur + 1, nums, sum + nums[cur]);
        t.removeLast();

    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        Target = target;
        dfs(false, 0, candidates, 0);
        return ans;
    }
}
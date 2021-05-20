class Solution {
    // https://leetcode-cn.com/problems/combinations/submissions/
    List<List<Integer>> ans = new LinkedList<>();
    LinkedList<Integer> t = new LinkedList<>();
    int N;
    int K;
    void dfs(int cur){

        if(t.size() == K){
            ans.add(new ArrayList(t));
            return;
        }
        if(cur > N) return;
        t.add(cur);
        dfs(cur + 1);
        t.removeLast();
        dfs(cur + 1);
    }
    public List<List<Integer>> combine(int n, int k) {
        N = n;
        K = k;
        dfs(1);
        return ans;
    }
}
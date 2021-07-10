class Solution {
    // https://leetcode-cn.com/problems/unique-binary-search-trees/submissions/
    HashMap<Integer, Integer> map = new HashMap<>();
    public int dfs(int num){
        if(num <= 1) return 1;
        if(map.containsKey(num)) return map.get(num);
        int cnt = 0;
        for(int i = 0; i < num; ++i){
            cnt += dfs(i) * dfs(num - 1 - i);
        }
        map.put(num, cnt);
        return cnt;
    }
    public int numTrees(int n) {
        int ans = dfs(n);
        return ans;
    }
}

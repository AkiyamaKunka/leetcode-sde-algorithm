//https://leetcode-cn.com/problems/all-paths-from-source-to-target/

class Solution {
    List<List<Integer>> ans;
    void dfs(int x, int[][] graph, LinkedList<Integer> path){
        if(x == graph.length - 1){
            path.add(x);
            ans.add(new ArrayList<>(path));
            return;
        }
        path.add(x);
        for (int i = 0; i < graph[x].length; i++) {
            dfs(graph[x][i], graph, path);
            path.removeLast();
        }
    }
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        ans = new ArrayList<>();
        dfs(0, graph, new LinkedList<>());
        return ans;
    }
}
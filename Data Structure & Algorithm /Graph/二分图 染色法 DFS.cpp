

class Solution {
    int n; // number of the vertax
    bool valid; // the boolean value to judge the outcome
    vector<int> color; // 0 is uncolered, 1 is red and 2 is blue
public:

    void dfs(int v, int c, vector<vector<int>> g){
        color[v] = c;
        int c2 = (c == 1 ? 2 : 1);
        for (int i = 0; i < g[v].size(); i++){
            int nv = g[v][i];
            if(color[nv] == 0){ // uncolored, so we continue to search
                dfs(nv, c2, g);
                if(!valid)  // in the dfs the value might be change
                    return; // so you have to check the eligibility at any time
            }else if(color[nv] == c) {
                valid = false;
                return;
            }
        }

    }

    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        color = vector<int> (n);
        valid = true;
        for (int i = 0; i < n && valid; i++){
            if(color[i] == 0)
                dfs(i, 1, graph);
        }
        return valid;
    }
};
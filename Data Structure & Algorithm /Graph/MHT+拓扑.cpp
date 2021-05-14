class Solution {
    // https://leetcode-cn.com/problems/minimum-height-trees/
    int * id;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            vector<int> ans;
            ans.emplace_back(0);
            return ans;
        }
        id = new int[n];
        for(int i = 0; i < n; i++)
            id[i] = 0;
        vector<vector<int>> map (n, vector<int>(0));
        for(auto & it : edges){
            map[it[0]].emplace_back(it[1]);
            map[it[1]].emplace_back(it[0]);
            id[it[0]]++;
            id[it[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(id[i] == 1)
                q.push(i);
        }
        int cnt = 0;
        while(!(n - cnt == 2 || n - cnt == 1)){
            int _cnt = q.size();
            while(_cnt--){
                int node = q.front();
                q.pop();
                cnt++;
                id[node]--;
                for(int i = 0; i < map[node].size(); i++){
                    int n_node = map[node][i];
                    if(id[n_node] != 0){
                        id[n_node]--;
                        if(id[n_node] == 1)
                            q.push(n_node);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.emplace_back(q.front());
            q.pop();
        }
        return ans;
    }
};
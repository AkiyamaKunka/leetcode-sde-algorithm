class Solution {
public:
    //https://leetcode-cn.com/problems/course-schedule-iv/

    // 这道题的关键是使用无序set来进行查询，把N2算法降低成MNlgN

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>id(n);
        vector<set<int>>ans (n, set<int>()); // restore the pre of each course


        vector<vector<int>> edge(n, vector<int>(0));
        for(auto iter : prerequisites){
            int s = iter[0];
            int e = iter[1];
            edge[s].push_back(e);
            id[e]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++){
            if(id[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for (int i = 0; i < edge[p].size(); i++){
                int cur = edge[p][i];
                id[cur]--;
                if(id[cur] == 0)
                    q.push(cur);

                ans[cur].insert(p);
                for (auto it = ans[p].begin(), end = ans[p].end(); it != end ; ++it){
                    ans[cur].insert(*it);
                }
            }
        }

        vector<bool> find(queries.size(), false);
        for (int i = 0; i < queries.size(); i++){
            int s = queries[i][0];
            int e = queries[i][1];
            if(ans[e].count(s))
                find[i] = true;
        }
        return find;
    }
};

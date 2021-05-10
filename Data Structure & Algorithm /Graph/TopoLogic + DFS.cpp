//https://leetcode-cn.com/problems/course-schedule-ii/submissions/
class Solution {

    vector<int> visited; // 0 not yet, 1 visiting, 2 visited;
    vector<vector<int>> edge;
    vector<int> ans;
    bool valid;

public:

    void addEdge(int e, int b){
        edge[b].push_back(e);
    }

    void dfs(int x){
        if(visited[x] == 1){
            valid = false;
        }
        else if(visited[x] == 2)
            return;
        else{ // not visited yet
            visited[x] = 1;
            for (auto beg = edge[x].begin(); beg != edge[x].end() ; beg++){
                if(!valid) return;
                dfs(*beg);
            }
            visited[x] = 2;
            ans.push_back(x);
            return;
        }

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses);
        edge.resize(numCourses);
        valid = true;
        for (int i = 0; i < prerequisites.size(); i++)
            addEdge(prerequisites[i][0], prerequisites[i][1]);
        for (int i = 0; i < numCourses; i++){
            if(!valid)
                return {}; // return an empty vector
            if(!visited[i])
                dfs(i);
        }

        reverse(ans.begin(),ans.end()); // here succeed
        return ans;
    }
};
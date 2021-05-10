class Solution1 {
    //https://leetcode-cn.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
    // 怀疑题错了
    vector<vector<int>> g;
    int maxDis;
    int N;
    int dfs(int cur, int curDis, vector<int> & vis){
        vis[cur] = 1; // visted
        int _num = 1;
        for (int i = 0; i < N; i++){
            if(vis[i] == 0 && g[cur][i] != -1 && curDis + g[cur][i] <= maxDis){
                _num += dfs(i, curDis + g[cur][i], vis);
            }
        }
        cout << "return _num" << _num << endl;
        return _num;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans = -1;
        int ansNum = 1000;
        N = n;
        g = vector<vector<int>>(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            g[i][i] = 0;
        maxDis = distanceThreshold;
        for(auto & it : edges){
            g[it[0]][it[1]] = it[2];
            g[it[1]][it[0]] = it[2];
        }
        for (int i = 0; i < n; i++){
            cout << "i is " << i << endl;
            vector<int>vis(n, 0);
            int _num = dfs(i, 0, vis);
            if(ansNum >= _num){
                ansNum = _num;
                ans = i;
            }
        }
        return ans;
    }
};
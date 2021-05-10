class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int K) {
        const int INF = 1000000;
        vector<vector<int>>g(n, vector<int>(n, INF));
        vector<int>dist(n, INF);
        vector<bool>touch(n, false);
        for(auto &v : times){
            g[v[0] - 1][v[1] - 1] = v[2];
        }

        dist[K - 1] = 0; // 这么做的操作是让后边的循环把k - 1 这个初始点选中，
        // 然后执行 更新距离的操作
        // touch 放在函数体里做
        for (int i = 0; i < n - 1; i++){
            int index = -1; // 未来要选中的点的坐标
            for (int j = 0; j < n; j++){
                if(!touch[j] && (index == -1 || dist[j] < dist[index])){
                    index = j;
                }
            }
            touch[index] = true; // 选中了最短距离的点
            for (int m = 0; m < n; m++){
                dist[m] = min(g[index][m] + dist[index], dist[m]);
            }
        }


        int ans = * max_element(dist.begin(), dist.end());
        return ans == INF ? -1 : ans;
    }
};


class Solution4 {
    // https://leetcode-cn.com/problems/maximal-network-rank/
    int * id;
    int map[102][102];
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        for (int i = 0; i < 102; i++)
            for (int j = 0; j < 102; j++)
                map[i][j] = -1;

        id = new int[n];
        for (int i = 0; i < n; i++)
            id[i] = 0;
        for(auto & it : roads){
            id[it[0]]++;
            id[it[1]]++;
            map[it[0]][it[1]] = 1;
            map[it[1]][it[0]] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++){
                int cnt = id[i] + id[j];
                if(map[i][j] == 1) cnt--;
                if(cnt > ans) ans = cnt;
            }
        return ans;
    }
};
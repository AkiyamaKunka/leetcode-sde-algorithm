class Solution {
    int N;
    int * vis;
    bool ans;
    int cnt;
    void dfs(int x, vector<vector<int>>& rooms){
        cnt++;
        vis[x] = 1;
        if(cnt == N){ans = true; return;}
        for(int i = 0; i < rooms[x].size(); i++){
            int nx = rooms[x][i];
            if(!vis[nx])
                dfs(nx, rooms);
        }

    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        N = rooms.size();
        ans = false;
        cnt = 0;
        vis = new int[N];
        for(int i = 0; i < N; i++){
            vis[i] = 0;
        }
        dfs(0, rooms);
        return ans;
    }
};
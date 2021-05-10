class Solution7 {
    //https://leetcode-cn.com/problems/the-maze-ii/submissions/
    int n;
    int m;
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    int ans;
    int * visDis;
    const int MAX = 9999999;
    bool isBoard(int x, int y, vector<vector<int>>& maze){
        if(x < 0 || y < 0 || x >= m || y >= n || maze[x][y] == 1) return false;
        return true;
    }
    void dfs(int x, int y, int dis, vector<vector<int>>& maze, vector<int>& destination){
        if(dis > visDis[x * n + y])
            return;
        if(x == destination[0] && y == destination[1]){

            ans = dis;
            return;
        }
        for(int i = 0; i < 4; i++){
            int _x = x;
            int _y = y;
            int cnt = 0;
            while(isBoard(_x + dx[i], _y + dy[i], maze)){
                _x += dx[i];
                _y += dy[i];
                cnt++;
            }
            if(visDis[x * n + y] + cnt < visDis[_x * n + _y] ) {
                //cout << " temp dis is " << visDis[x * n + y] + cnt << endl;
                visDis[_x * n + _y] = visDis[x * n + y] + cnt;
                dfs(_x, _y, visDis[_x * n + _y], maze, destination);
            }
        }
    }
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
        m = maze.size();
        n = maze[0].size();
        ans = MAX;
        visDis = new int[m * n];
        for(int i = 0; i <  m * n; i++) {
            visDis[i] = MAX;
        }
        visDis[start[0] * n + start[1]] = 0;
        dfs(start[0], start[1], 0, maze, destination);
        return ans == MAX ? -1 : ans;
    }
};

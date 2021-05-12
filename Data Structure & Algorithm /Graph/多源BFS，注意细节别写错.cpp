class Solution {
    // https://leetcode-cn.com/problems/map-of-highest-peak/submissions/
    int m;
    int n;
    int * map;  //i * n + j
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    void init(vector<vector<int>>& isWater){
        m = isWater.size();
        n = isWater[0].size();
        map = new int[m * n];
        for(int i = 0; i < m * n; i++){
            map[i] = -1;
        }
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        init(isWater);
        cout << "init" << endl;
        vector<vector<int>>ans(m, vector<int>(n, 0));
        queue<int> q;
        cout << m << " " << n << endl;
        cout << isWater.size();


        for(int i = 0; i < isWater.size(); i++){
            for(int j = 0; j < isWater[0].size(); j++){
                cout << "i:" << i << " j:" << j << endl;
                if(i == 2) break;
                if(isWater[i][j]){
                    //q.push(i * n + j);
                    cout << "q.push" << endl;
                    //ans[i][j] = 0;
                    cout << "ans set" << endl;
                    //map[i * n + j] = 1;
                    cout << "map set" << endl;
                }
            }
        }
        cout << "all set" << endl;
        int depth = 0;
        while(!q.empty()){
            int cnt = q.size();
            cout << "cnt: " << cnt << endl;
            depth++;
            while(cnt--){
                int x = q.front() % n;
                int y = q.front() / n;
                cout << "x: " << x << " y: " << y << endl;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || !map[ny * n + nx]){
                        continue;
                    }
                    map[ny * n + nx] = 1;
                    ans[ny][nx] = depth;
                    q.push(ny * n + nx);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:

    //https://leetcode-cn.com/problems/flower-planting-with-no-adjacent/solution/lin-jie-biao-suan-fa-ran-hou-hashkuai-yu-set-by-yo/
    // 染色问题，这是我一开始比较麻烦的解法

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>g(n, vector<int>(0));
        const int C[4] = {1, 2, 3, 4};
        vector<int>color(n, 0);
        for(auto & v : paths){
            g[v[0] - 1].push_back(v[1] - 1);
            g[v[1] - 1].push_back(v[0] - 1);
        }
        // bfs
        for (int i = 0; i < n; i++) {
            if(color[i])
                continue;
            queue<int> q;
            q.push(i); // push as the first point
            while (!q.empty()) {

                int p = q.front();
                q.pop();

                bool tempC[4] = {true, true, true, true};
                for (auto &v : g[p]) {
                    // v is the linked edge
                    if (color[v]) {
                        tempC[color[v] - 1] = false;
                    } else {
                        q.push(v);
                    }
                    for (int i = 0; i < 4; i++) {
                        if (tempC[i]) {
                            color[p] = i + 1;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < color.size(); i++){
            if(!color[i])
                color[i] = 1;
        }

        return color;
    }



    // 这里给出更好的解法
    vector<int> gardenNoAdj_better_version(int n, vector<vector<int>>& paths) {

    }


    // 其实只需要遍历所有点就行了，不用搜索


};





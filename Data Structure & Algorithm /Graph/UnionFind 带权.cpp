class Solution {
    //https://leetcode-cn.com/problems/evaluate-division/submissions/
    // very easy to make mistakes, need to be very careful
    unordered_map<string, int> m;
    double * w;
    int * fa;
    int n;
    int find(int x){
        if(fa[x] != x){
            int f = find(fa[x]);
            w[x] *= w[fa[x]];
            fa[x] = f;
        }
        return fa[x];
    }
    void unit(int x, int y, double xy_v){
        int fx = find(x); int fy = find(y);
        fa[fx] = fy;
        w[fx] = xy_v * w[y] / w[x];
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        int id = 0;
        vector<double>ans;
        for (auto & it : equations){ if(m.find(it[0]) == m.end()) m[it[0]] = id++; if(m.find(it[1]) == m.end()) m[it[1]] = id++;}
        fa = new int[id];
        w = new double[id];
        for (int i = 0; i < id; i++){ w[i] = 1.0; fa[i] = i;}
        for (int i = 0; i < n; i++) unit(m[equations[i][0]], m[equations[i][1]], values[i]);
        for(auto & it: queries){
            double tv = -1.0;
            if(m.find(it[0]) != m.end() && m.find(it[1]) != m.end()){
                int fa = find(m[it[0]]); int fb = find(m[it[1]]);
                if(fa == fb) tv = w[m[it[0]]] / w[m[it[1]]];
            }
            ans.emplace_back(tv);
        }
        return ans;
    }
};
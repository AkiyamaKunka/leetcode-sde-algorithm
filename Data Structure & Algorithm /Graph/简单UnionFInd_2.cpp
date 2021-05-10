class Solution {
    // https://leetcode-cn.com/problems/redundant-connection/
private:
    int n;
    int * fa;
    vector<int>ans;
    int find(int x){
        if(x == fa[x]) return x;
        else return fa[x] = find(fa[x]);
    }
    void unit(int x, int y){
        fa[find(x)] = find(y);
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        ans = vector<int>(2);
        fa = new int[n + 1];  // just leave 0 alone
        for (int i = 0; i < n + 1; i++){
            fa[i] = i;
        }
        for(auto & it : edges){
            int fx = find(it[0]);
            int fy = find(it[1]);
            if(fx != fy) unit(fx, fy);
            else{
                ans[0] = it[0];
                ans[1] = it[1];
                break;

            }
        }
        return ans;
    }
};
class Solution {
    // https://leetcode-cn.com/problems/similar-string-groups/
    int * fa;
    int n;
    int cnt; // connected component
    int find(int x){
        if(x != fa[x]) fa[x] = find(fa[x]);
        return fa[x];
    }
    void unit(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx == fy) return ;
        fa[fx] = fy;
        cnt--;
    }

    void init(){
        fa = new int [n];
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
        cnt = n;
    }
    bool isConnected(int x, int y){
        return find(fa[x]) == find(fa[y]);
    }
    bool isEqual(string x, string y){
        int cnt = 0;
        for(int i = 0; i < x.size(); i++){
            if(x[i] != y[i]) cnt++;
            if(cnt > 2) return false;
        }
        return true;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        init();
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++){
                if(!isConnected(i, j) && isEqual(strs[i], strs[j]))
                    unit(i, j);
            }
        return cnt;
    }
};
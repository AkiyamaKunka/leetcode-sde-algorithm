class Solution2 {
    // https://leetcode-cn.com/problems/regions-cut-by-slashes/
    int * fa;
    int cc;
    int n;
    int find(int x){
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    void unit(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if(fx == fy) return;
        fa[fx] = fy;
        cc--;
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();  // vertexs will be 4 * n
        fa = new int[4 * n * n];
        cc = 4 * n * n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < 4; k++) // index = 8 * i + 4 * j + k
                    fa[4 * n * i + 4 * j + k] = 4 * n * i + 4 * j + k;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++){
                if(grid[i][j] == ' '){
                    // unit four
                    unit(4 * n * i + 4 * j + 0, 4 * n * i + 4 * j + 1);
                    unit(4 * n * i + 4 * j + 1, 4 * n * i + 4 * j + 2);
                    unit(4 * n * i + 4 * j + 2, 4 * n * i + 4 * j + 3);
                }else if(grid[i][j] == '/'){
                    // unit two
                    unit(4 * n * i + 4 * j + 1, 4 * n * i + 4 * j + 2);
                    unit(4 * n * i + 4 * j + 3, 4 * n * i + 4 * j + 0);
                }else if(grid[i][j] == '\\'){
                    // unit two
                    unit(4 * n * i + 4 * j + 0, 4 * n * i + 4 * j + 1);
                    unit(4 * n * i + 4 * j + 2, 4 * n * i + 4 * j + 3);
                }
                if(i != n - 1){
                    unit(4 * n * i + 4 * j + 2, 4 * n * (i + 1) + 4 * j + 0);
                }
                if(j != n - 1){
                    unit(4 * n * i + 4 * j + 1, 4 * n * i + 4 * (j + 1) + 3);
                }
            }
        return cc;
    }
};
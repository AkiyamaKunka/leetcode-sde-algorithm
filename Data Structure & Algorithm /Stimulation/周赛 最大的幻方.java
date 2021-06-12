class Solution {
    // https://leetcode-cn.com/contest/biweekly-contest-54/problems/largest-magic-square/
    int [][] sum;
    int m;
    int n;
    void constructMap(int[][] grid){
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = j + 1; k < n; ++k){ // horizontal
                    sum[i * n + j][i * n + k] = sum[i * n + j][i * n + k - 1] + grid[i][k];
                    sum[i * n + k][i * n + j] = sum[i * n + j][i * n + k];
                }
                for(int p = i + 1; p < m; ++p){ // vertical
                    sum[i * n + j][p * n + j] = sum[i * n + j][(p - 1) * n + j] + grid[p][j];
                    sum[p * n + j][i * n + j] = sum[i * n + j][p * n + j];
                }
                for(int k = j + 1, p = i + 1; k < n && p < m; ++p, ++k){  // diagonal
                    sum[i * n + j][p * n + k] = sum[i * n + j][(p - 1) * n + k - 1] + grid[p][k];
                    sum[p * n + k][i * n + j] = sum[i * n + j][p * n + k];
                }
            }
        }
    }
    boolean isBoard(int y, int x, int length){
        if(x + length >= n || y + length >= m) return false;
        return true;
    }

    boolean checkSum(int y, int x, int l){
        int sumVer = sum[y * n + x][(y + l) * n + x];
        int sumHor = sum[y * n + x][y * n + x + l];
        for(int dis = 0; dis < l; dis++){
            if(sum[(y + dis) * n + x][(y + dis) * n + x + l] != sumHor) return false;
            if(sum[(y) * n + x + dis][(y + l) * n + x + dis] != sumVer) return false;
        }
        if(sum[y * n + x][(y + l) * n + x + l] != sumVer) return false;
        if(sum[(y + l) * n + x][(y) * n + x + l] != sumHor) return false;
        return true;
    }

    public int largestMagicSquare(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        sum = new int[m * n][m * n]; // index = i * n + j
        constructMap(grid);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                for(int l = Math.min(m, n); l > 0; l--){
                    if(isBoard(i, j, l)){
                        if(checkSum(i, j, l)){
                            //System.out.println("Check i " + i + " and j " + j);
                            return l;
                        }
                    }
                }
            }
        }
        return -1;
    }
}
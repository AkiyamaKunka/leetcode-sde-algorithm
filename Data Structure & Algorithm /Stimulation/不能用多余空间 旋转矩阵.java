class Solution {
    public void rotate(int[][] matrix) {
        //https://leetcode-cn.com/problems/rotate-image/
        int n = matrix.length;
        if(n == 0 || n == 1){}
        else{
            for(int dis = 0; dis < n / 2; ++dis){
                int size = n - 2 * dis;
                for(int i = 0; i < size - 1; i++){

                    int first = matrix[dis][dis + i];
                    matrix[dis][dis + i] = matrix[dis + size - 1 - i][dis];
                    matrix[dis + size - 1 - i][dis] = matrix[dis + size - 1][dis + size - 1 - i];
                    matrix[dis + size - 1][dis + size - 1 - i] = matrix[dis + i][dis + size - 1];
                    matrix[dis + i][dis + size - 1] = first;
                }
            }
        }
    }
}
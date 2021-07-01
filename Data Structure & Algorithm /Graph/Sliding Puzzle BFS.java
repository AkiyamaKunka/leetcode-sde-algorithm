class Solution {
    // https://leetcode-cn.com/problems/sliding-puzzle/
    int [] dx = {1, -1, 0, 0};
    int [] dy = {0, 0, 1, -1};
    public boolean isBoard(int x, int y){
        if(x >= 0 && y >= 0 && x < 3 && y < 2){
            return true;
        }
        return false;
    }
    public String intToString(int[] array){
        String str = "";
        for(int it : array){
            str = str.concat(String.valueOf(it));
        }
        return str;
    }
    public int bfs(int[][] raw_board){
        int[] bd = new int[6];
        for(int i = 0; i < 6; ++i){ // index = i * 3 + j
            bd[i] = raw_board[i / 3][i % 3];
        }
        String bd_str = intToString(bd);
        String ans = "123450";
        if(ans.equals(bd_str)) return 0;
        HashMap<String, Integer> map = new HashMap<>();
        map.put(bd_str, 0);
        Queue<String> q = new LinkedList<>();
        q.add(bd_str);
        while(q.size() != 0){
            String cur_str = q.poll();
            for(int i = 0; i < 6; ++i){
                if(cur_str.charAt(i) == '0'){
                    int y = i / 3;
                    int x = i % 3;
                    for(int j = 0; j < 4; ++j){
                        int nx = x + dx[j];
                        int ny = y + dy[j];
                        if(isBoard(nx, ny)){
                            int[] next = new int[6];
                            for(int k = 0; k < 6; ++k){
                                next[k] = Character.getNumericValue(cur_str.charAt(k));
                            }
                            int temp = next[y * 3 + x];
                            next[y * 3 + x] = next[ny * 3 + nx];
                            next[ny * 3 + nx] = temp;
                            String next_str = intToString(next);
                            if(map.containsKey(next_str)){
                                continue;
                            }
                            int step = map.get(cur_str) + 1;
                            if(next_str.equals(ans)) {
                                return step;
                            }
                            map.put(next_str, step);
                            q.add(next_str);
                        }
                    }
                }
            }

        }
        return -1;
    }
    public int slidingPuzzle(int[][] board) {
        int ans = bfs(board);
        return ans;
    }
}
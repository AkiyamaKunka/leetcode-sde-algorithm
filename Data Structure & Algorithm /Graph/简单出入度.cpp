class Solution {
    // https://leetcode-cn.com/problems/find-the-town-judge/
    int * id;
    int * od;
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        id = new int[N];
        od = new int[N];
        for (int i = 0; i < N; i++){
            id[i] = 0;
            od[i] = 0;
        }
        for(auto & it : trust){
            id[it[1] - 1]++;
            od[it[0] - 1]++;
        }
        for (int i = 0; i < N; i++){
            if(id[i] == N - 1 && od[i] == 0) return i + 1;
        }
        return - 1;
    }
};

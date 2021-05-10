class Solution5 {
    //https://leetcode-cn.com/problems/couples-holding-hands/
    int * pos;
    int n;
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        n = row.size();
        pos = new int[n];
        for (int i = 0; i < n; i++)
            pos[row[i]] = i; // map from number to position which is index of in array row
        for (int i = 0; i < n; i += 2){
            int pair = row[i] ^ 1;
            if(pair == row[i + 1]) continue;
            else{
                ans++;
                int pos_pair = pos[pair];
                int nei = row[i + 1];
                swap(row[i + 1], row[pos_pair]);
                pos[nei] = pos_pair;
            }
        }
        return ans;
    }
};
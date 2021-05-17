class Solution {
    // https://leetcode-cn.com/problems/permutations/submissions/
    void dfs(vector<int> & output, int first, int length, vector<vector<int>>& ans){
        if(first == length){
            ans.emplace_back(output);
            return;
        }
        for(int i = first; i < length; ++i){
            swap(output[i], output[first]);
            dfs(output, first + 1, length, ans);
            swap(output[i], output[first]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums, 0, nums.size(), ans);
        return ans;
    }
};
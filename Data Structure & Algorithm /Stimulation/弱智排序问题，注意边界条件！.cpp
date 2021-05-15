class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // https://leetcode-cn.com/problems/merge-sorted-array/submissions/
        vector<int> ans;
        int p1 = 0;
        int p2 = 0;
        for(int i = 0; i < m + n; i++){
            if(p1 >= m && p2 < n){
                ans.emplace_back(nums2[p2]);
                p2++;
            }else if(p2 >= n && p1 < m){
                ans.emplace_back(nums1[p1]);
                p1++;
            }
            else if(nums1[p1] < nums2[p2]){
                ans.emplace_back(nums1[p1]);
                p1++;
            }else{
                ans.emplace_back(nums2[p2]);
                p2++;
            }
        }
        for(int i = 0; i < m + n; i++)
            nums1[i] = ans[i];
    }

};
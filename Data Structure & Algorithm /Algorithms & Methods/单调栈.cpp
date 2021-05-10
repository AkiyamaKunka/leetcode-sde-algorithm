class Solution {
    // https://leetcode-cn.com/problems/next-greater-element-i/
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        vector<int> ans;
        for (int i = 0; i < nums2.size(); i++){
            while(!s.empty() && s.top() < nums2[i]){
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(!s.empty()){
            m.emplace(s.top(), -1);
            s.pop();
        }
        for (int i = 0; i < nums1.size(); i++){
            ans.emplace_back(m.at(nums1[i]));
        }
        return ans;
    }
};
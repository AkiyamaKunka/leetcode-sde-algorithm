class Solution {
    // https://leetcode-cn.com/problems/cracking-the-safe/submissions/
    unordered_set<string> vis;
    string ans;
    int k;
    int n;
    void dfs(string node){
        for (int i = 0; i < k; i++){
            string path = node + to_string(i);
            if(!vis.count(path)){
                vis.insert(path);
                string nextNode = path.substr(path.length() - (n - 1), path.length());
                dfs(nextNode);
            }
        }
        ans += node.substr(node.length() - 1, node.length());
    }
public:
    string crackSafe(int n, int k) {
        this->k = k;
        this->n = n;
        if(n == 1){
            string s;
            for(int i = 0; i < k; i++)
                s += to_string(i);
            return s;
        }
        dfs(string(n - 1, '0'));
        return ans + string(n - 2, '0');
    }
};
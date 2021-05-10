
class Solution {
    // https://leetcode-cn.com/problems/reconstruct-itinerary/solution/zhong-xin-an-pai-xing-cheng-by-leetcode-solution/
    // the relationship covers a map from the start point to the end point,
    // and the sub-map is to store how many edges are there from start point to end point,
    // we use an ordered map to ensure that the answer is ordered in alphabet.
    unordered_map<string, map<string, int>> g;
    vector<string> ans; // to store the path
    int N; // the number of tickets

    bool dfs(string dest){
        ans.emplace_back(dest);
        if(ans.size() == N + 1) return true; // should be noted that the number of tickets = destination + 1
        for(auto & it: g[dest]){
            if(it.second > 0){
                it.second--;
                if(dfs(it.first)) return true;
                // if the program runs to here, means the path is not eligible, so you're gonna return a false
                // which means to recover the status
                ans.pop_back();
                it.second++;
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        N = tickets.size();
        for (auto & it: tickets){
            g[it[0]][it[1]]++;
        }
        dfs("JFK");
        return ans;
    }
}

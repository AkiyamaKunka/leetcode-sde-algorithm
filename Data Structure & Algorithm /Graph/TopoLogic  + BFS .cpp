#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <sstream>
#include <map>
#include <random>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>
#include <utility>
#include <stack>
#include <deque>
#include <queue>
#include <string>
#include <cctype>
using namespace std;
//#define LOCAL
#define INF 1000000;
const int maxn =102;

class Solution {  // https://leetcode-cn.com/problems/course-schedule/
 public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            int * inDegree = new int[numCourses];
            for (int i = 0; i < numCourses; i++)
                inDegree[i] = 0;
            queue<int> q;
            vector<vector<int>> edge(numCourses, vector<int>(0));
            for (int i = 0; i < prerequisites.size(); i++){
                edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
                inDegree[prerequisites[i][0]]++;
            }
            for (int i = 0; i < numCourses; i++){
                if(inDegree[i] == 0){
                    q.push(i);
                }
            }
            int cnt = 0;
            while(!q.empty()){
                int point = q.front();
                q.pop();
                cnt++;
                for (int i = 0; i < edge[point].size(); i++){
                    int finishPoint = edge[point][i];
                    inDegree[finishPoint]--;
                    if(inDegree[finishPoint] == 0)
                        q.push(finishPoint);
                }
            }
            return cnt == numCourses;
        }
};

int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled7/input.txt", "r", stdin);
    freopen("/Users/robertwong/CLionProjects/untitled7/output.txt","w",stdout);
#endif
    Solution * mySolution = new Solution();
    vector<vector<int>> ves;
    vector<int> a{1, 0};

    ves.push_back(a);
    //ves.push_back(b);


    cout << mySolution->canFinish(2,ves);

    return 0;
}

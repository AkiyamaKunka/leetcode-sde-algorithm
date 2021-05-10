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
#include <vector>
#include <utility>
#include <stack>
#include <deque>
#include <queue>
#include <string>
#include <cctype>
#include <list>
using namespace std;
#define LOCAL
#define INF 10000000
#define MAX 10000
const int maxn = 200;


// 来源 https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies/
// 细节非常容易错，需要做两次拓扑排序，熟悉了细节就没问题了


class Solution {

    vector<vector<int>> outerGroup;
    vector<vector<int>> outerEdge;
    vector<int> outerInDegree;

public:

    int findGroup(int x){
        for (int i = 0; i < outerGroup.size(); i++){
            for (int j = 0; j < outerGroup[i].size(); j++){
                if(x == outerGroup[i][j])
                    return i;
            }
        }
        return -1;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems){

        outerGroup = vector<vector<int>> (n - m, vector<int>(0));
        // 外层index是组的序号，内层index是项目的序号


        for (int i = 0; i < n; i++){
            // i是项目的序号，group[i]表示其归属的组
            if(group[i] == -1)
                continue;
            outerGroup[group[i]].push_back(i);
        }
        for (int i = 0; i < n; i++){
            if(group[i] == -1){
                vector<int> tempVec(1, i);
                outerGroup.push_back(tempVec);
            }
        }
        // 处理原始数据

        // 接下来开始建立组间的拓扑排序

        outerEdge = vector<vector<int>> (outerGroup.size(), vector<int>(0));
        outerInDegree  = vector<int>(outerGroup.size(), 0);


        // 建立组之间的边，并且初始化以组为定点的各点入度
        for (int i = 0; i < beforeItems.size(); i++){
            for (int j = 0; j < beforeItems[i].size(); j++){
                outerEdge[findGroup(beforeItems[i][j])].push_back(findGroup(i));
                outerInDegree[findGroup(i)]++;
            }
        }

        // 开始用bfs实现组的拓扑排序

        queue<int> outerBfs;
        vector<int> outerAns;
        int outerCnt = 0;


        // 入度为0的组全部放入queue中准备进行bfs
        for (int i = 0; i < outerGroup.size(); i++){
            if(outerInDegree[i] == 0)
                outerBfs.push(i);
        }

        while(!outerBfs.empty()) {

            int point = outerBfs.front();
            outerBfs.pop();
            outerCnt++;

            // 把答案放进vector中
            outerAns.push_back(point);

            for (int i = 0; i < outerGroup[point].size(); i++) {
                outerInDegree[outerGroup[point][i]]--;
                if (outerInDegree[outerGroup[point][i]] == 0)
                    outerBfs.push(outerGroup[point][i]);
            }
        }

        // 如果组的拓扑排序无法完成，就返回空数组
        if(outerCnt != outerGroup.size()){
            vector<int> wrongAns;
            return wrongAns;
        }

        //接下来继续进行单个组内的各个项目的拓扑排序
        vector<int>finalAns;
        for (int i = 0; i < outerAns.size(); i++){

            int GroupIndex = outerAns[i];

            // 开始对这个组内建立拓扑排序需要的数据结构
            int GroupSize = outerGroup[GroupIndex].size();
            vector<int>inDegree(GroupSize, 0);
            vector<vector<int>>edge(GroupSize, vector<int>(0));
            // 初始化

            // 接下来是建立边的联系
            for (int j = 0; j < GroupSize; j++){
                int cur = outerGroup[GroupIndex][j];
                // 这里的cur是组内 正在被遍历的 项目
                for (int k = 0; k < beforeItems[cur].size(); k++){
                    edge[beforeItems[cur][k]].push_back(cur);
                    inDegree[cur]++;
                    // 建立入度
                }
            }

            int cnt = 0;
            queue<int> bfs;
            for (int j = 0; j < inDegree.size(); j++)
                if(inDegree[j] == 0)
                    bfs.push(j);
            while(!bfs.empty()){
                int point = bfs.front();
                finalAns.push_back(point);
                bfs.pop();
                cnt++;
                for (int j = 0; j < edge[point].size(); j++){
                    inDegree[edge[point][j]]--;
                    if(inDegree[edge[point][j]] == 0)
                        bfs.push(edge[point][j]);
                }
            }
            if(cnt != GroupSize){
                vector<int> wrongAns;
                return wrongAns;
            }
        }

        return finalAns;
    }
};

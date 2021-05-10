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
using namespace std;
//#define LOCAL
const int maxn =102;

struct Edge{
    int b,e,v;
    Edge(int b, int e, int v): b(b), e(e), v(v){}
};

bool cmp(Edge x, Edge y){
    return x.v < y.v;
}

class Solution{
    int val[maxn][maxn];
    int n; // node number
    int m; // edge number

    vector<Edge> len;
    int fa[maxn];
    int ans;
    int total;

public:
    int find(int x){
        if(fa[x] == x) return x;
        else return fa[x] = find(fa[x]);
    }

    void unite(int node){
        ans += len[node].v;
        fa[find(len[node].b)] = find(len[node].e);
    }

    Solution() {
        total = 0;
        ans = 0;
        Edge headEdge(0,0,0);
        len.push_back(headEdge); // initialization
        cin >> n >> m;
        for (int i = 0; i < m; i++){
            int b, e, v;
            cin >> b >> e >> v;
            total += v;
            Edge tempEdge(b, e, v);
            len.push_back(tempEdge);
        }
        sort(len.begin() + 1, len.end(), cmp);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        int cnt = 0;
        for(int i = 1; i < len.size(); i++){
            if(cnt == n - 1) break;
            if(find(len[i].b) == find(len[i].e)) continue;
            else{
                unite(i);
                cnt++;
            }
        }
        cout << ans;
    }
};

int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled7/input.txt", "r", stdin);
    freopen("/Users/robertwong/CLionProjects/untitled7/output.txt","w",stdout);
#endif

    Solution * mySolution = new Solution();
    return 0;
}
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
#define INF 10000
const int maxn =102;


class Solution{
    int n;
    int p;
    int mapVal[maxn][maxn]; // 0 means no path
    int dis[maxn]; // distance of center point to all others
    int fa[maxn]; // union_find
    int pre[maxn];
    queue<int> seq;
public:
    Solution(){
        cin >> n;

        int edgeNumber;
        cin >> edgeNumber;
        int begin, end, val;
        init();
        for (int i = 0; i < edgeNumber; i++){
            cin >> begin >> end >> val;
            mapVal[begin][end] = val;

        }
        cin >> p;
        for (int i = 1; i <= n; i++){

            dis[i] = mapVal[p][i]; // 只有1个点的时候的dis
            pre[i] = p; // 记录前倾

        }
        Dijkstra();
        print();
    }

    void Dijkstra(){

        for (int i = 0; i < n; i++) {

            int tempMin = INF;
            int tempPos = p;
            for (int i = 1; i <= n; i++) // 开始找T集合以外的点
                // 排除已经进入T的点
                if (find(i) != find(p) && dis[i] < tempMin && dis[i] != 0) // 寻找到最小值
                {
                    tempMin = dis[i];
                    tempPos = i;
                }
            if(tempMin == INF) break;
            seq.push(tempPos);
            for (int i = 1; i <= n; i++)
                if (i!= p && find(i) != find(p) && tempMin == dis[i]) {
                    build(i, p);    //并入集合T
                }

            for (int i = 1; i <= n; i++) {
                if (find(i) != find(p) && i != tempPos && mapVal[tempPos][i] + dis[tempPos] < dis[i]) {
                    dis[i] = mapVal[tempPos][i] + dis[tempPos];
                    pre[i] = tempPos;

                }
            }
        }
    }
    void init(){
        for (int i = 1; i <= n; i++) {
            fa[i] = i;                            // 初始化 fa[]
            for (int j = 1; j <= n; j++) {
                if (i != j)
                    mapVal[i][j] = INF;
            }
        }
    }
    void print(){

        int cnt = 1;

        while(!seq.empty()){

            cout << "No." << cnt << " : ";
            int num = seq.front();
            stack <int> tempPrint;
            cout << p << " ";
            while(num != p){

                tempPrint.push(num);
                num = pre[num];
            }
            while(!tempPrint.empty()){
                cout << "-> " << tempPrint.top() << " ";
                tempPrint.pop();
            }
            cout << ", d = " << dis[seq.front()];
            seq.pop();
            cout << endl;
            cnt ++;
        }

        bool judge = false;
        for (int i = 1; i <= n; i++)
            if(dis[i] == INF){
                if(!judge)
                    cout << "No." << cnt << " : No Path to";
                judge = true;
                cout << " " << i;
            }
    }
    int find(int x){
        if(x == fa[x]) return fa[x];
        else return find(fa[x]);
    }
    void build(int son, int father){
        fa[find(son)] = find(father);
    }
};

int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled7/input.txt", "r", stdin);
    freopen("/Users/robertwong/CLionProjects/untitled7/output.txt","w",stdout);
#endif

    Solution * sample = new Solution();
    return 0;
}

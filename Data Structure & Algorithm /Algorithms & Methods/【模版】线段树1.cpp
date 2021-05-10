//https://www.luogu.com.cn/problem/P3372

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include <ctime>
#include <sstream>
#include <map>
//#define LOCAL
#define maxn 100005
#define maxm 30000
#define INF 10000000
using namespace std;

int n, m;
int x[4*maxn], y[4*maxn];   //第i个节点存储的值为[x[i], y[i])
int left_node[4*maxn], right_node[4*maxn];   //左节点和右节点
long long sum[4*maxn];   //当前节点下属的最低一层节点的和
int lazy[4*maxn];   //当前节点存储了多少个加法值没有下发
int cnt = 0;

long long build_tree(int x0, int y0)
{
    int now = cnt;
    x[now] = x0; y[now] = y0; lazy[now] = 0; sum[now] = 0;
    if(y0 == x0+1) scanf("%lld", &sum[now]);
    else
    {
        int m0 = (y0-x0)/2+x0;
        left_node[now] = ++cnt; sum[now] += build_tree(x0, m0);
        right_node[now] = ++cnt; sum[now] += build_tree(m0, y0);
    }
    return sum[now];
}

void add_value(int x0, int y0, int k, int node)
{
    sum[node] += k*(y0-x0);
    if(x[node] == x0 && y[node] == y0) { lazy[node] += k; return; }
    int m0 = (y[node]-x[node])/2+x[node];
    if(x0 >= m0) { add_value(x0, y0, k, right_node[node]); return; }
    if(y0 <= m0) { add_value(x0, y0, k, left_node[node]); return; }
    add_value(x0, m0, k, left_node[node]);
    add_value(m0, y0, k, right_node[node]);
}

long long get_sum(int x0, int y0, int node)
{
    if(x[node] == x0 && y[node] == y0) return sum[node];
    int m0 = (y[node]-x[node])/2+x[node];
    int r_node = right_node[node], l_node = left_node[node];
    sum[r_node] += (y[r_node]-x[r_node])*lazy[node]; lazy[r_node] += lazy[node];
    sum[l_node] += (y[l_node]-x[l_node])*lazy[node]; lazy[l_node] += lazy[node];
    lazy[node] = 0;
    if(x0 >= m0) return get_sum(x0, y0, right_node[node]);
    if(y0 <= m0) return get_sum(x0, y0, left_node[node]);
    return get_sum(x0, m0, left_node[node])+get_sum(m0, y0, right_node[node]);
}

int main()
{
#ifdef LOCAL
    freopen("data.in.txt","r",stdin);
    freopen("data.out.txt","w",stdout);
#endif
    cin >> n >> m;
    build_tree(1, n+1);
    int state, x0, y0, k;
    for(int i = 0; i < m; i++)
    {
        cin >> state;
        if(state == 1)
        {
            scanf("%d%d%d", &x0, &y0, &k);
            add_value(x0, y0+1, k, 0);
        }
        if(state == 2)
        {
            scanf("%d%d", &x0, &y0);
            printf("%lld\n", get_sum(x0, y0+1, 0));
        }
    }
    return 0;
}


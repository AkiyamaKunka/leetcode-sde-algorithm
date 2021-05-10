//建立动态链表

#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <sstream>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
using namespace std;
const int maxn=1000001;
#define LOCAL
#define SIZE sizeof(struct ST)

struct ST
{
    int num;
    float  score;
    struct ST *next ;
};

struct ST* creat_graphic(int n)
{
    struct ST *p1,*p2,*head;
    p1=p2=(struct ST*)malloc(SIZE);
    int o_n=n;
    cin>>p1->num>>p1->score;

    while(n>0)
    {
        if(n==o_n)head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct ST*)malloc(SIZE);
        cin>>p1->num>>p1->score;
        n--;
    }
    p2->next=NULL;
    return head;
}

void print_f(struct ST* head)
{
    struct ST *p;
    p=head;
    do{
        cout << p->num <<" "<< p->score<<endl;
        p = p->next;
    }while(p!=NULL);
}

int main() {
#ifdef LOCAL
    freopen("data.in.txt", "r", stdin);
    freopen("data.out.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    print_f(creat_graphic(n));
    return 0;
}


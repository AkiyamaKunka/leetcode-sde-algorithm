#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <windows.h>
using namespace std;

//先手的棋子为-1，后手的棋子为1,没有子的地方为0
//参数还未确定

int board[7][7]={0};   //当前棋盘
long long value[7][7]={{0,0,0,0,0,0,0},{0,1,2,3,2,1,0},{0,2,4,5,4,2,0},{0,3,5,6,5,3,0},{0,2,4,5,4,2,0},{0,1,2,3,2,1,0},{0,0,0,0,0,0,0}};   //棋盘每个位置的初始权值
long long link[5]={0,2,4,1000,100000000};   //对于我方已有1，2，3，4个棋子连接时的权值（前提是该行，列，对角线上没有敌方棋子）
long long broke[5]={0,2,4,100,100000};   //对于敌方已有1，2，3，4个棋子时的情况进行破坏的权值（前提是该行，列，对角线没有己方棋子）
long long ti;   //计算机下棋速度参数


void usetime()
{
    int k=1;
    for(int i=1;i<=ti;i++)
    {
        k=(k+i)%5;
    }
}

void AItime()
{
    cout<<"请选择计算机的落子速度(1,2,3,4)"<<endl;
    char w;
    cin>>w;
    if(w=='1') ti=300000000;
    else if(w=='2') ti=200000000;
    else if(w=='3') ti=100000000;
    else if(w=='4') ti=50000000;
    else
    {
		Beep(300,400);Beep(600,400); Beep(600,400); 
        cout<<"计算机下的飞快，这就是你愚弄计算机的代价"<<endl;
        ti=0;
    }
}


long long getValue(int i,int j)   //计算每个点的权值
{
    long long ans=value[i][j];


    int own=0;
    for(int t=1;t<=5;t++)
    {
        if(board[t][j]==-1) own++;
        else if(board[t][j]==1) { own=0; break;}
    }
    ans+=link[own];

    own=0;
    for(int t=1;t<=5;t++)
    {
        if(board[i][t]==-1) own++;
        else if(board[i][t]==1) { own=0; break;}
    }
    ans+=link[own];

    own=0;
    if(i==j)
    {
        for(int t=1;t<=5;t++)
        {
            if(board[t][t]==-1) own++;
            else if(board[t][t]==1) { own=0; break;}
        }
        ans+=link[own];
    }

    own=0;
    if(i==6-j)
    {
        for(int t=1;t<=5;t++)
        {
            if(board[t][6-t]==-1) own++;
            else if(board[t][6-t]==1) { own=0; break;}
        }
        ans+=link[own];
    }


    int rival=0;
    for(int t=1;t<=5;t++)
    {
        if(board[t][j]==1) rival++;
        else if(board[t][j]==-1) { rival=0; break;}
    }
    ans+=broke[rival];

    rival=0;
    for(int t=1;t<=5;t++)
    {
        if(board[i][t]==1) rival++;
        else if(board[i][t]==-1) { rival=0; break;}
    }
    ans+=broke[rival];

    rival=0;
    if(i==j)
    {
        for(int t=1;t<=5;t++)
        {
            if(board[t][t]==1) rival++;
            else if(board[t][t]==-1) { rival=0; break;}
        }
        ans+=broke[rival];
    }

    rival=0;
    if(i==6-j)
    {
        for(int t=1;t<=5;t++)
        {
            if(board[t][6-t]==1) rival++;
            else if(board[t][6-t]==-1) { rival=0; break;}
        }
        ans+=broke[rival];
    }

    return ans;
}

void AI(int k)   //困难人机
{
    cout<<"电脑落子："<<endl;
    usetime();
    int best_i=0,best_j=0;
    long long best=0;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
        {
            if(board[i][j]!=0) continue;
            else
            {
                long long v=getValue(i,j);
                if(v>best)
                {
                    best=v;
                    best_i=i; best_j=j;
                }
            }
        }
    board[best_i][best_j]=k;
}

void zAI(int k)   //普通人机
{
    cout<<"电脑落子："<<endl;
    usetime();
    int best_i=0,best_j=0;
    long long best=0;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
        {
            if(board[i][j]!=0) continue;
            else
            {
                long long v=getValue(i,j);
                if(v>best)
                {
                    best=v;
                    best_i=i; best_j=j;
                }
            }
        }
    if(best>=100000) board[best_i][best_j]=k;
    else
    {
        srand(time(NULL));
        while(true)
        {
            int i=(rand())%5+1,j=(rand())%5+1;
            if(board[i][j]!=0) continue;
            else { board[i][j]=k; break;}
        }
    }
}

void zzAI(int k)   //简单人机
{
    srand(time(NULL));
    cout<<"电脑落子："<<endl;
    usetime();
    while(true)
    {
        int i=(rand())%5+1,j=(rand())%5+1;
        if(board[i][j]!=0) continue;
        else { board[i][j]=k; break;}
    }
}


void work(int k)   //玩家落子（修改棋盘）
{
    cout<<"请落子："<<endl;
    char i,j;
    cin>>i>>j;
    if(i<'1'||i>'5'||j<'1'||j>'5'||board[i-48][j-48]!=0)
    {
		Beep(300,400);Beep(600,400); Beep(600,400); 
        cout<<"不要试图欺骗计算机，我们永远会把客户当成智障，请重新落子："<<endl;
        work(k);
    }
    else
    {
        board[i-48][j-48]=k;
        return;
    }
}


void print()
{
    char p_board[7][7];
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
        {
            if(board[i][j]==1) p_board[i][j]='X';
            else if(board[i][j]==-1) p_board[i][j]='O';
            else if(board[i][j]==0) p_board[i][j]=' ';
        }
    printf("+---+---+---+---+---+\n"
           "| %c | %c | %c | %c | %c |\n"
           "+---+---+---+---+---+\n"
           "| %c | %c | %c | %c | %c |\n"
           "+---+---+---+---+---+\n"
           "| %c | %c | %c | %c | %c |\n"
           "+---+---+---+---+---+\n"
           "| %c | %c | %c | %c | %c |\n"
           "+---+---+---+---+---+\n"
           "| %c | %c | %c | %c | %c |\n"
           "+---+---+---+---+---+\n",
           p_board[1][1],p_board[1][2],p_board[1][3],p_board[1][4],p_board[1][5],
           p_board[2][1],p_board[2][2],p_board[2][3],p_board[2][4],p_board[2][5],
           p_board[3][1],p_board[3][2],p_board[3][3],p_board[3][4],p_board[3][5],
           p_board[4][1],p_board[4][2],p_board[4][3],p_board[4][4],p_board[4][5],
           p_board[5][1],p_board[5][2],p_board[5][3],p_board[5][4],p_board[5][5]);
    cout<<endl;
}


int check()
{
    int win=0;
    for(int i=1;i<=5;i++)
    {
        if(board[i][1]==0) continue;
        int j;
        for(j=2;j<=5;j++)
        {
            if(board[i][j]!=board[i][1]) break;
        }
        if(j==6) {win=board[i][1]; return win;}
    }

    for(int j=1;j<=5;j++)
    {
        if(board[1][j]==0) continue;
        int i;
        for(i=2;i<=5;i++)
        {
            if(board[i][j]!=board[1][j]) break;
        }
        if(i==6) {win=board[1][j]; return win;}
    }

    if(board[1][1]!=0)
    {
        int t;
        for(t=2;t<=5;t++)
        {
            if(board[t][t]!=board[1][1]) break;
        }
        if(t==6) {win=board[1][1]; return win;}
    }

    if(board[1][5]!=0)
    {
        int t;
        for(t=2;t<=5;t++)
        {
            if(board[t][6-t]!=board[1][5]) break;
        }
        if(t==6) {win=board[1][5]; return win;}
    }
    int full=1;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
        {
            if(board[i][j]==0) {full=0; goto next;}
        }
    next:;
    if(full==1) return 100;
    return win;
}  //检测胜负情况


int choose1()
{
    char x;
    cin>>x;
    int t=x-48;
    if(x!='0'&&x!='1'&&x!='2')
    {
		Beep(600,400); Beep(600,400); Beep(600,400); 
        cout<<"不要试图欺骗计算机，我们永远会把客户当成智障，请重新选择："<<endl;
        t=choose1();
    }
    return t;
}

int choose2()
{
    char x;
    cin>>x;
    int t=x-48;
    if(x!='0'&&x!='1')
    {
		Beep(600,400); Beep(600,400); Beep(600,400); 
		cout<<"不要试图欺骗计算机，我们永远会把客户当成智障，请重新选择："<<endl;
        t=choose2();
    }
    return t;
}
int main()
{ 
    newgame:;
    memset(board,0,sizeof(board));
    cout<<"游戏提示：先手为X，后手为O，输入格式：x y，可以尝试不按要求输入【/滑稽】"<<endl;
    print();
    AItime();
    cout<<"人机对战选择0，人人对战选择1，机机对战选择2："<<endl;
    int x=choose1();
    if(x==0)
    {
        cout<<"选择先手输入0，选择后手输入1："<<endl;
        int choose=choose2();
        cout<<"难度选择：简单选择0，中等选择1，困难选择2："<<endl;
        int y=choose1();
        if(choose==0)
        {
            while(true)
            {
                work(1);
                print();
                if(check()==1) {Beep(300,400);Beep(600,400); Beep(600,400);  cout<<"666太强了!"<<endl; break;}
                if(check()==100) { Beep(600,400); Beep(600,400); Beep(600,400); cout<<"恭喜你与人工智障打成平手"<<endl; break;}
                if(y==1) zAI(-1);
                else if(y==0) zzAI(-1);
                else if(y==2) AI(-1);
                print();
                if(check()==-1) {Beep(500,400); Beep(500,400); Beep(500,400);  cout<<"好好反思一下自己的所做所为"<<endl; break;}
                if(check()==100) {Beep(700,200); Beep(700,200); Beep(700,200); cout<<"恭喜你与人工智障打成平手"<<endl; break;}
            }
        }
        if(choose==1)
        {
            while(true)
            {
                if(y==1) zAI(1);
                else if(y==0) zzAI(1);
                else if(y==2) AI(1);
                print();
                if(check()==1) {Beep(500,400); Beep(500,400); Beep(500,400);  cout<<"好好反思一下自己的所做所为"<<endl; break;}
                if(check()==100) {Beep(700,200); Beep(700,200); Beep(700,200); cout<<"恭喜你与人工智障打成平手"<<endl; break;}
                work(-1);
                print();
                if(check()==-1) {Beep(300,400);Beep(600,400); Beep(600,400);  cout<<"dalao tql!"<<endl; break;}
                if(check()==100) { Beep(300,400);Beep(600,400); Beep(600,400); cout<<"恭喜你与人工智障打成平手"<<endl; break;}
            }
        }
    }
    if(x==1)
    {
        while(true)
        {
            work(1);
            print();
            if(check()==1) { cout<<"先手获胜"<<endl; break;}
            if(check()==100) { cout<<"恭喜你们打成平手"<<endl; break;}
            work(-1);
            print();
            if(check()==-1) { cout<<"后手获胜"<<endl; break;}
            if(check()==100) { cout<<"恭喜你们打成平手"<<endl; break;}
        }
    }
    if(x==2)
    {
        cout<<"为什么你们想看两个人工智障打架？"<<endl;
        cout<<"选择第一个人工智障难度：简单选择0，中等选择1，困难选择2："<<endl;
        int x1=choose1();
        cout<<"选择第二个人工智障难度：简单选择0，中等选择1，困难选择2："<<endl;
        int x2=choose1();
        while(true)
        {
            if(x1==1) zAI(1);
            else if(x1==0) zzAI(1);
            else if(x1==2) AI(1);
            print();
            if(check()==1) {Beep(300,400);Beep(600,400); Beep(600,400);  cout<<"第一个人工智障获胜"<<endl; break;}
            if(check()==100) {Beep(300,400);Beep(600,400); Beep(600,400);  cout<<"好了，打平了，满意了吧？"<<endl; break;}
            if(x2==1) zAI(-1);
            else if(x2==0) zzAI(-1);
            else if(x2==2) AI(-1);
            print();
            if(check()==-1) {Beep(300,400);Beep(600,400); Beep(600,400);  cout<<"第二个人工智障获胜"<<endl; break;}
            if(check()==100) { Beep(300,400);Beep(600,400); Beep(600,400); cout<<"好了，打平了，满意了吧？"<<endl; break;}
        }
    }
    cout<<"是否重来一局：是（1），否（0）"<<endl;
    int is_n=choose2();
    if(is_n==1) goto newgame;
    else
    {
        cout<<"感谢您的参与"<<endl;
        return 0;
    }
}

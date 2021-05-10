#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
//#define LOCAL
const int maxn =1000000;

int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled5/data_in.txt", "r", stdin);
    freopen("/Users/robertwong/CLionProjects/untitled5/data_out.txt","w",stdout);
#endif
    string ans;
    cin >> ans;
    stack<char> temp;
    for (int i = 0; i < ans.size(); i++){
        if(!temp.empty() && (temp.top() == ans[i] + 32 || temp.top() == ans[i] - 32) ){
            temp.pop();
        }
        else
            temp.push(ans[i]);
    }
    if(temp.empty())
        cout << -1;
    else{
        vector<char>out;
        while (!temp.empty()) {
            out.push_back(temp.top());
            temp.pop();
        }
        for (int i = out.size() - 1; i >= 0; i--)
            cout << out[i];
    }
    return 0;
}

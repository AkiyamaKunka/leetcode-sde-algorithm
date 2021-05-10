#include <cstdio>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include <ctime>
#include <sstream>
#include <map>

#include <unordered_set>
#include <unordered_map>



#include <iostream>
using namespace std;
#define LOCAL
const int maxn =1000000;
double calcu(char sym, float num1, float num2){
    cout << "the opr is " << sym << " and the number is " << num1 << " " << num2 << endl;
    if(sym == '*') return num1 * num2;
    if(sym == '/') return num2 / num1;
    if(sym == '+') return num1 + num2;
    if(sym == '-') {
        cout << "the minus number is " << num2 - num1 << endl;
        return num2 - num1;}

    if(sym == '%') {
        cout << "the number is " << (int)num2 << "and num2 is " << (int)num1 << endl;
        return ((int)num2 )% ((int)num1);}
}


int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled5/data_in.txt", "r", stdin);
    freopen("/Users/robertwong/CLionProjects/untitled5/data_out.txt","w",stdout);
#endif


    string equ;
    cin >> equ;
    cout << "the array is" << equ << endl;
    stack<char> symbo;
    stack<float> num;



    for (int i = 0; i < equ.length(); i++) {
        char opr = equ[i];
        if (opr == '(') {
            symbo.push(opr);

            cout << " here we push the symbo" << opr << endl;
        } else if (opr == ')') {
            cout << "saw a right backet" << endl;
            while (symbo.top() != '(') {
                float num1 = num.top();
                num.pop();
                float num2 = num.top();
                num.pop();
                float outcome = calcu(symbo.top(),num1, num2);
                num.push(outcome);
                symbo.pop();
            }

            symbo.pop();


        } else if( opr == '+' || opr == '-'){

            if( !symbo.empty() && (symbo.top() == '*' || symbo.top() == '/' || symbo.top() == '%') ) {

                cout << "got a +" << endl;
                do{
                    float num1 = num.top();
                    num.pop();
                    float num2 = num.top();
                    num.pop();
                    float outcome = calcu(symbo.top(), num1, num2);

                    num.push(outcome);

                    symbo.pop();

                }while (symbo.top() == '*' || symbo.top() == '/' || symbo.top() == '%');
                symbo.push(opr);
            }
            else{
                cout << "got a +" << endl;
                symbo.push(opr);
                cout << " here we push the symbo" << opr << endl;
            }


        } else if( opr == '*' || opr == '/' || opr == '%'){
            symbo.push(opr);
            cout << " here we push the symbo" << opr << endl;
        } else {
            num.push((float)opr-48);
            cout << "here the number " << (int)opr-48 << " is in stack" << endl;
        }
        cout << "we are in the crile " << i + 1 << endl;
    }

    while (!symbo.empty()){
        float num1 = num.top();
        num.pop();
        float num2 = num.top();
        num.pop();
        float outcome = calcu(symbo.top(), num1, num2);
        symbo.pop();
        num.push(outcome);
    }
    printf("%0.2f",num.top());
    return 0;
}

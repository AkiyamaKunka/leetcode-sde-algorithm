#include <cmath>
#include <stack>
#include <string>
#include <iostream>
using namespace std;
#define LOCAL
const int maxn =1000000;

double calcu(char sym, float num1, float num2){
    //cout << "the opr is " << sym << " and the number is " << num1 << " " << num2 << endl;
    if(sym == '*') return num1 * num2;
    if(sym == '/') return num2 / num1;
    if(sym == '+') return num1 + num2;
    if(sym == '-') {
        //cout << "the minus number is " << num2 - num1 << endl;
        return num2 - num1;}

    if(sym == '%') {
        //cout << "the number is " << (int)num2 << "and num2 is " << (int)num1 << endl;
        return ((int)num2 )% ((int)num1);}
    if(sym == '^') {
        return pow(num2, num1);
    }
}

bool check(stack<float> & elem, bool & check ){
    if (elem.empty()){
        check = false;
        return false;
    }else
        return true;
}

bool check(stack<char> & elem, bool & check ){
    if (elem.empty()){
        check = false;
        return false;
    }else
        return true;
}

int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled5/data_in.txt", "r", stdin);
    freopen("/Users/robertwong/CLionProjects/untitled5/data_out.txt","w",stdout);
#endif


    string equ;

    while(cin >> equ) {
        //cout << "the array is" << equ << endl;
        stack<char> symbo;
        stack<float> num;
        bool judge = true;

        if (equ.empty())
            judge = false;

        for (int i = 0; i < equ.length(); i++) {
            char opr = equ[i];
            if (opr == '(') {
                if (((float) equ[i - 1] - 48 >= 0 && (float) equ[i - 1] - 48 < 10)) {
                    judge = false;
                    break;
                }
                symbo.push(opr);

                //cout << " here we push the symbo" << opr << endl;
            } else if (opr == ')') {
                if (!check(symbo, judge))break;
                if ((i + 1) < equ.length() && (float) equ[i + 1] - 48 >= 0 && (float) equ[i + 1] - 48 < 10) {
                    judge = false;
                    break;
                }
                //cout << "saw a right backet" << endl;
                while (symbo.top() != '(') {
                    if (!check(num, judge))break;
                    float num1 = num.top();
                    num.pop();

                    if (!check(num, judge))break;
                    float num2 = num.top();
                    num.pop();

                    float outcome = calcu(symbo.top(), num1, num2);
                    num.push(outcome);
                    symbo.pop();
                }

                symbo.pop();


            } else if (opr == '+' || opr == '-') {
                if (!check(symbo, judge))break;
                if (!symbo.empty() &&
                    (symbo.top() == '*' || symbo.top() == '/' || symbo.top() == '%' || symbo.top() == '^')) {

                    //cout << "got a +" << endl;
                    do {
                        if (!check(num, judge))break;
                        float num1 = num.top();
                        num.pop();
                        if (!check(num, judge))break;
                        float num2 = num.top();
                        num.pop();
                        float outcome = calcu(symbo.top(), num1, num2);
                        num.push(outcome);
                        symbo.pop();

                    } while (symbo.top() == '*' || symbo.top() == '/' || symbo.top() == '%' || symbo.top() == '^');
                    symbo.push(opr);
                } else {

                    //cout << "got a +" << endl;
                    symbo.push(opr);
                    //cout << " here we push the symbo" << opr << endl;
                }


            } else if (opr == '*' || opr == '/' || opr == '%') {
                //if(!check(symbo, judge))break;
                if (!symbo.empty() && symbo.top() == '^') {
                    do {
                        if (!check(num, judge))break;
                        float num1 = num.top();
                        if (!check(num, judge))break;
                        num.pop();
                        float num2 = num.top();
                        num.pop();
                        float outcome = calcu(symbo.top(), num1, num2);

                        num.push(outcome);

                        symbo.pop();

                    } while (symbo.top() == '^');
                    symbo.push(opr);
                } else {
                    symbo.push(opr);
                    //cout << " here we push the symbo" << opr << endl;
                }
            } else if (opr == '^') {
                symbo.push(opr);
            } else {
                num.push((float) opr - 48);
                //cout << "here the number " << (int)opr-48 << " is in stack" << endl;
            }
            //cout << "we are in the crile " << i + 1 << endl;
        }

        while (!symbo.empty() && judge) {
            if (!check(num, judge))break;
            float num1 = num.top();
            num.pop();
            if (!check(num, judge))break;
            float num2 = num.top();
            num.pop();
            float outcome = calcu(symbo.top(), num1, num2);
            symbo.pop();
            num.push(outcome);
        }
        if (judge) {
            printf("%0.2f\n", num.top());
        } else {
            cout << "ERROR IN INFIX NOTATION" << endl;
        }
    }
    return 0;
}

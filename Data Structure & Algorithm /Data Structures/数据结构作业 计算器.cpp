#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <iostream>
using namespace std;
//#define LOCAL
const int maxn =1000000;

char infoC[17] = {'+', '-', '%', '*', '/', '^' ,'.', '1', '2', '3', '4', '5', '6', '7', '8', '9' ,'0'};
int info[6] = {0, 1, 3, 3, 3, 4};

double calcu(char sym, double num1, double num2){
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

//bool check(stack<double> & elem, bool & check ){
//    if (elem.empty()){
//        check = false;
//        return false;
//    }else
//        return true;
//}
//
//bool check(stack<char> & elem, bool & check ){
//    if (elem.empty()){
//        check = false;
//        return false;
//    }else
//        return true;
//}



bool higher( char top, char bot){
    int t, b;
    for (int i = 0; i < 6; i++){
        if(top == infoC[i]) t = info[i];
        if(bot == infoC[i]) b = info[i];
    }
    if(t < b || (t == b && (t == 1 || t == 3 ) ))
        return false;
    else
        return true;
}


void cal(stack<char> & symbo, stack<double> & num){

    //check(symbo, cor);
    char sym = symbo.top();
    //cout << "symbol " << sym << " out" << endl;
    symbo.pop();
    double num1 = num.top();
    //cout << "num1 " << num1 << "out" << endl;
    num.pop();
    double num2 = num.top();
    //cout << "num2 " << num2 << "out" << endl;
    num.pop();

    double outcome = calcu(sym, num1, num2);
    //cout << "outcome " << outcome << " in numStack" << endl;
    num.push(outcome);
}


int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled5/data_in.txt", "r", stdin);
    freopen("/Users/robertwong/CLionProjects/untitled5/data_out.txt","w",stdout);
#endif

    string r;
    while(cin >> r) {


        vector<char>equ;
        double numq[1000];

        int i = 0;
        while(i < r.length()){
            if( r[i] >= '0' && r[i] <= '9' ){

                vector<double>num; // found the head digit XD
                num.push_back((double)r[i]-48);

                i++;
                while(r[i] >= '0' && r[i] <= '9'){
                    //cout << "here push " << r[i] << endl;
                    num.push_back((double)r[i]-48);
                    i++;
                }

                double outcome = 0;
                for (int j = 0; j < num.size(); j++){
                    outcome += num[j] * pow(10, num.size() - j - 1);
                }
                //cout << "the number here is " << outcome << endl;
                num.clear();


                vector<double> num2;
                if(i < r.length() && r[i] == '.'){
                    i++;
                    while(r[i] >= '0' && r[i] <= '9'){
                        //cout << "now we get a small number" << r[i] << endl;
                        num2.push_back((double)r[i] - 48);
                        i++;
                    }
                    for (int j = 0; j < num2.size(); j++){
                        //cout << "here the samll number is " << num2[j] << endl;
                        //cout << "here the samll number's power is " << (double)1 / (double)pow(10, (j + 1)) << endl;
                        outcome += num2[j] * ( (double)1 / (double)pow(10, (j + 1)) );
                    }
                }
                num2.clear();
                //cout << "the number here is " << outcome << endl;
                equ.push_back('#');
                numq[equ.size() - 1] = outcome;

            }else{
                equ.push_back(r[i]);
                i++;
            }
        }
//        for (int j = 0; j < equ.size(); j++){
//            if(equ[j] == '#')
//                cout << numq[j];
//            else
//                cout << equ[j];
//        }
        //cout << endl << "all info get " << endl;
        // now to check the mistakes

        bool correction = true;


        stack <char>bcheck;
        for (int j = 0; j < equ.size(); j++){



            if(equ[j] == '(') {

                if(j + 1 < equ.size() && ( equ[j + 1] != '#' )){
                    correction = false;
                    break;
                }                                //first check cannot support 2 () or )(


                bcheck.push(equ[j]);
                //cout << "the " << bcheck.top() << " is bcheck " << endl;
            }
            else if(equ[j] == ')'){

                if(j + 1 < equ.size() && equ[j + 1] == '('){
                    correction = false;
                    break;
                }                                //first check cannot support 2 () or )(


                //cout << "got a right bracket" << endl;
                if (bcheck.empty() || bcheck.top() != '('){
                    //cout << "the top of bcheck wrong, it's " << bcheck.top() << endl;
                    correction = false;
                    break;
                }else{
                    //cout << "went else" << endl;
                    if(!bcheck.empty())
                        bcheck.pop();
                    else{  // stack empty
                        correction = false;
                        break;
                    }
                }
            }else if(equ[j] !='#'){

            }


        }
        if (!bcheck.empty() )
            correction = false;


        //cout << "the correction is " << correction << endl;

        //cout << "the array is" << equ << endl;
        stack<char> symbo;
        stack<double> num;
        if(correction) {
            for (int j = 0; j < equ.size(); j++){
                char opr = equ[j];
                if(opr == '('){

                    symbo.push(opr);

                }else if( opr == ')'){

                    while(symbo.top() != '('){

                        cal(symbo, num);
                        // pop all the */%+-^
                    }
                    symbo.pop();       // pop the '('

                }else if( opr == '#'){                          // push number

                    num.push(numq[j]);

                }else{                                          // push the symbol

                    if(symbo.empty())
                        symbo.push(opr);
                    else{
                        //cout << "opr " << opr << " and symbo.top " << symbo.top() << " compare" << endl;// already a symbol in stack
                        if(higher(opr, symbo.top())){
                            //cout << "push " << opr << "in symboStack" << endl;
                            symbo.push(opr);
                        }else{
                            while( (!(symbo.empty() || symbo.top() == '(') && (!higher(opr, symbo.top() ))   )   ) // might hiden mistakes
                                cal(symbo, num);
                            symbo.push(opr);
                        }
                    }
                }
            }  // now calculate rest elemets in stack num and symbo
            //cout << "is symboStack empty?" << symbo.empty() << endl;
            while(!symbo.empty()){
                cal(symbo, num);
            }
            //cout << "is symboStack empty?" << symbo.empty() << endl;

        }

        if (correction) {
            printf("%0.2f\n", num.top());
        } else {
            loop:
            cout << "ERROR IN INFIX NOTATION" << endl;
        }

    }
    return 0;
}

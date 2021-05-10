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
#include <list>
#include <vector>
#include <utility>
#include <stack>
#include <deque>
#include <queue>
#include <string>
#include <cctype>
//#define LOCAL
#define INF 1000000
using namespace std;
const int maxn =102;

class node{
    int data;
    int height;
    node * left;
    node * right;
public:
    friend class AVL;
};

class AVL{
    node * head;
    bool judge;
public:
    AVL(int value){
        judge = false;
        head = new node;
        head->data = value;
        head->left = NULL;
        head->right = NULL;
        head->height = 0;
        //cout << "head is built" << endl;
    }
    void searchData(int target) {
        searchData(head, target);
    }
    void searchData(node * x, int target){
        if(x){
            if(x->data == target)
                cout << "the target value: " << x->data << " exits" << endl;
            else if(x->data < target) searchData(x->right, target);
            else searchData(x->left, target);
        }else
            cout << "Data not found" << endl;
    }

    node * treeRotateRight(node * x) {                      // x' s balance factor is 2
        node * tempLeft = x->left;
        x->left = tempLeft->right;                          // give son's right to x's left
        tempLeft->right = x;                                // exchange father and son
                                                            // then update new point's height
        x->height = treeHeight(x);
        tempLeft->height = treeHeight(tempLeft);

        return tempLeft;
    }

    node * treeRotateLeft(node * x){
        node * tempRight = x->right;
        x->right = tempRight->left;
        tempRight->left = x;

        x->height = treeHeight(x);
        tempRight->height = treeHeight(tempRight);

        return tempRight;
    }

    node * treeRebalance(node * x){

        int factor = getTreeBalanceFactor(x);
        //cout << "balance factor of " << x->data << " is " << factor << endl;
        if(factor > 1) {
            if(head->data == x->data)
                judge = true;
            if (getTreeBalanceFactor(x->left) > 0)          // LL right rotate * 1
            {
                //cout << "LL" << endl;
                return treeRotateRight(x);
            }
            else {                                          // LR left rotate + right rotate
                //cout << "LR" << endl;
                x->left = treeRotateLeft(x->left);
                return treeRotateRight(x);
            }

        }else if(factor < -1){// RR
            if(head->data == x->data)
                judge = true;
            if(getTreeBalanceFactor(x->right) < 0){
                //cout << "RR" << endl;
                return treeRotateLeft(x);
            }
            else {
                //cout << "RL" << endl;
                x->right = treeRotateRight(x->right);       // RL
                return treeRotateLeft(x);
            }
        }else {                                             // do not need rebalance
            return x;
        }
    }
    int treeHeight(){
        return treeHeight(head);
    }
    int treeHeight(node * x){
        if(x == NULL) return 0;
        else return max(treeHeight(x->left), treeHeight(x->right)) + 1;
    }

    int getHeight(node * x){
        if(x == NULL) return 0;
        else return x->height;
    }
    int getTreeBalanceFactor(node * x){
        if(x == NULL) return 0;
        else return getHeight(x->left) - getHeight(x->right);
    }
    void treeInsert(int value){
        treeInsert(head, value);
    }
    node * treeInsert(node * x, int value){
        if(!x){
            x = new node;                                    // create a new node with target value
            x->left = x->right = NULL;
            x->data = value;
            x->height = 1;
        }
        else {
            if (x->data == value) {
                cout << "you inserted a repeated value" << endl;
                exit(0);                                     // not allow repeated value
            } else if (x->data > value)
                x->left = treeInsert(x->left, value);
            else x->right = treeInsert(x->right, value);

            x->height = treeHeight(x);                       // update height

            x = treeRebalance(x);                            // balance the tree
            if(judge) // root is moved
            {
                head = x;
                judge = false;
            }
        }
        //cout << "insert " << x->data << " bf is " << getTreeBalanceFactor(x) << endl;
        //cout << "head is " << head->data << endl;
        return x;
    }
    void treeDelete(node * x, int value) {

    }
    void preOrderTraverse(){
        preOrderTraverse(head);
    }

    void preOrderTraverse(node * x){
        if(x == NULL) {
            cout << "null" << endl;
            return;
        }
        else{
            cout << "node value " << x->data << " height is " <<
                 getHeight(x) << " bf is " << getTreeBalanceFactor(x) << endl;
            preOrderTraverse(x->left);
            preOrderTraverse(x->right);
        }
    }
    void test(){
    }

    void levelOrder(int n){
        queue<node> q;
        queue<int> id;
        q.push(*head);
        id.push(1);
        priority_queue<int, vector<int>, less<int>> ans;    // A declining queue
        bool isFirstTime = true;
        while(!q.empty()){
            node * temp = new node;
            temp = &q.front();
            if(isFirstTime) {
                cout << temp->data;
                isFirstTime = false;
            }
            else cout << " " << temp->data;
            int tempId;
            tempId = id.front();
            ans.push(tempId);
            if(temp->left) {q.push(*temp->left); id.push(2 * tempId);}
            if(temp->right) {q.push(*temp->right); id.push(2* tempId + 1);}
            q.pop();
            id.pop();
        }
        if(ans.top() == n)
            cout << endl << "Yes";
        else cout << endl << "No";

    }


};

int main() {
#ifdef LOCAL
    freopen("/Users/robertwong/CLionProjects/untitled7/input.txt", "r", stdin);
    freopen("/Users/robertwong/CLionProjects/untitled7/output.txt","w",stdout);
#endif
    int n;
    cin >> n;
    int num;
    cin >> num;
    AVL * myTree = new AVL(num);

    while(cin >> num)
        myTree->treeInsert(num);

    //myTree->preOrderTraverse();
    myTree->levelOrder(n);
    //myTree->searchData(10);
    return 0;
}

#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>

#include <queue>

using namespace std;
class myHeap {
private:
    int p;
    vector<long long int> arr;

public:

    myHeap() {
        p = 0;
        arr.push_back(-1);
    }

    void insert(long long int x) {
        p++;
        arr.push_back(x);
        swim();
    }

    int pop() {
        long long int temp = arr[1];

        show();
        arr[1] = arr[p];
        p--;

        sink(1);
        return temp;
    }

    void sink(int k) {
        int index = k;
        if (2 * k <= p && arr[index] > arr[2 * k])
            index = 2 * k;
        if (2 * k + 1 <= p && arr[index] > arr[2 * k + 1])
            index = 2 * k + 1;
        if (index != k) {
            exch(k, index);
            sink(index);
        }
    }

    void swim() {
        int k = p;
        cout << endl << "arr[k] is " << arr[k] << " and arr[k / 2] is " << arr[k / 2] << endl;
        while ((k / 2) > 0 && arr[k] < arr[k / 2]) {
            exch(k, k / 2);
            k /= 2;
            cout << "number exchanged" << endl;
        }
    }

    void exch(int a, int b) {
        long long int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    void show() {
        cout << "Here is all the elements in the tree ";
        for (int i = 1; i <= p; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

};
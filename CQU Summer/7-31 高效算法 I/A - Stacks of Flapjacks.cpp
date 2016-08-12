#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define mem(a,n) memset(a,n,sizeof(a))
const int inf = 1 << 30;
const int maxn = 10000 + 5;

int data[50];
int target[50];

int ifEnd(int count) {
    int flag = 1;
    for (int i = 0; i < count; i++) {
        if (target[i] != data[i]) {flag = 0;break;}
    }
    return flag;
}

int findMaxPos(int count) {
    int max = -1;
    int pos = -1;
    for (int i = 0; i < count; i++) {
        if (data[i] > max) {max = data[i]; pos = i;}
    }
    return pos;
}

void flip(int end)
{
    for (int i = 0; i < end / 2; i++) {
        int temp = data[i];
        data[i] = data[end - 1 - i];
        data[end - 1 - i] = temp;
    }
}


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    string input;
    while (getline(cin, input)) {
        cout << input << endl;
        istringstream in(input);
        
        int count = 0;
        while (!in.eof()) {
            int temp;
            in >> temp;
            data[count++] = temp;
        }
        memcpy(target, data, sizeof(data));
        sort(target, target + count);
        int total = count;
        while (!ifEnd(count))
        {
            int maxPos = findMaxPos(count);
            if (maxPos == count - 1) {
                cout << total - count + 1 << " " << total - count + 1 << " ";
            }
            else {
                if (maxPos == 0) {
                    flip(count);
                    cout << total - count + 1 << " ";
                } else {
                    flip(maxPos + 1);
                    cout << total - maxPos << " ";
                    flip(count);
                    cout << total - count + 1 << " ";
                }
            }
            count--;
        }
        cout << "0" << endl;
    }

    
    return 0;
}



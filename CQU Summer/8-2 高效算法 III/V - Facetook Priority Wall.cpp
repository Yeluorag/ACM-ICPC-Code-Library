#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = t; i < n; i ++)
#define ALL(v) v.begin(), v.end()
const int inf = 1 << 30;
const int N = 100 + 5;

int n;
struct node{
    int s;
    string nam;
}stu[N];
map<string, int > mp;
bool cmp(node &a, node &b) {
    return a.s == b.s ? a.nam < b.nam : a.s > b. s;
}
string chair;
string in;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    cin >> chair;
    cin >> n;
    getchar();
    rep(i, n) {
        getline(cin, in);
        stringstream ss(in);
        string s1, s2, ac, t;
        char tmp[N];
        int score = 0;
        ss >> s1;
        ss >> ac;
        if(ac[0] == 'p') {
            ss >> t;
            score = 15;
        } else if(ac[0] == 'c') {
            ss >> t;
            score = 10;
        } else if(ac[0] == 'l') score = 5;
        
        ss >> tmp;
        tmp[strlen(tmp) - 2] = '\0';
        s2 = tmp;
        
        if(s1 != chair && s2 != chair) {
            if(mp.find(s1) == mp.end()) mp[s1] = 0;
            if(mp.find(s2) == mp.end()) mp[s2] = 0;
        } else {
            if(s1 == chair) mp[s2] += score;
            if(s2 == chair) mp[s1] += score;
        }
    }
    
    int num = 0;
    map<string, int > ::iterator it;
    for(it = mp.begin(); it != mp.end(); it ++) {
        stu[num].nam = it->first;
        stu[num++].s = it->second;
    }
    sort(stu, stu + num, cmp);
    rep(i, num) cout << stu[i].nam << endl;
    return 0;
}
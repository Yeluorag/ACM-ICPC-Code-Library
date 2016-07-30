#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n;
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);

    scanf("%d",&n);
    cin.get();
    while(n--){
        string s;
        getline(cin, s);
        stack<char>st;
        int len=s.size(),ans=1;
        for(int i=0;i<len;i++){
            if(s[i]=='('||s[i]=='[') st.push(s[i]);
            else if(!st.empty()&&s[i]==')'&&st.top()=='(')st.pop();
            else if(!st.empty()&&s[i]==']'&&st.top()=='[')st.pop();
            else ans=0;
        }
        if(ans&&st.empty()) puts("Yes");
        else puts("No");
    }
    return 0;
}
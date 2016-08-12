#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1005],n,cas=0,ans;

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n),n){
        int temp;
        while(scanf("%d",&temp),temp){
            ans=1;
            queue<int>a;
            a.push(temp);
            stack<int>st;
            for(int i=1;i<n;i++) {
                scanf("%d",&temp);
                a.push(temp);
            }
            for(int i=1;i<=n;i++){
                st.push(i);
                while(!a.empty()&&!st.empty()){
                    if(a.front()==st.top()){
                        st.pop();
                        a.pop();
                    }else break;
                }
            }
            if(!a.empty()||!st.empty())ans=0;
            printf("%s\n",ans?"Yes":"No");
        }
        puts("");
    }
    return 0;
}
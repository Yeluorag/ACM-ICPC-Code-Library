#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int n,df[1005],bf[1005],hs[1005],hs2[1005];
vector<int>son[1005];

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
        memset(hs,-1,sizeof(hs));
        memset(hs2,-1,sizeof(hs));
        for(int i=0;i<n;i++){
            scanf("%d",&bf[i]);
            hs[bf[i]]=i;
            son[bf[i]].clear();
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&df[i]);
            hs2[df[i]]=i;
        }
        stack<int> st;
        st.push(df[0]);
        for(int i=1;i<n;i++){
            while(!st.empty()){
                int u=st.top();
                if(hs[u]<hs[df[i]]-1||u==bf[0]){
                    st.push(df[i]);
                    son[u].push_back(df[i]);
                    break;
                }else st.pop();
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d:",i);
            for(int j=0;j<son[i].size();j++) printf(" %d",son[i][j]);
            puts("");
        }
        
    }
    return 0;
}
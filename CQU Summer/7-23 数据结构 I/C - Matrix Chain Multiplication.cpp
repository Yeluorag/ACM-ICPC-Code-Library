#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn=105;

int n,row[30],col[30],ans;
char s[maxn];
struct node{
    int row,col;
}a[maxn];

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        char c;
        scanf("%c",&c);
        scanf("%d%d",&row[c-'A'],&col[c-'A']);
        getchar();
    }
   	while(scanf("%s",s)!=EOF){
        ans=0;
        stack<node> st;
        int len=strlen(s);
        for(int i=0;i<len;i++){
            if(s[i]=='(')continue;
            if(s[i]==')'){
                node k1=st.top();st.pop();
                node k2=st.top();st.pop();
                if(k2.col!=k1.row){
                    ans=-1;
                    break;
                }
                ans+=k2.row*k2.col*k1.col;
                k1.row=k2.row;
                st.push(k1);
            }else{
                node temp;
                temp.row=row[s[i]-'A'];
                temp.col=col[s[i]-'A'];
                st.push(temp);
            }
        }
        if(ans==-1)printf("error\n");
        else printf("%d\n",ans);
        
    }
    return 0;
}


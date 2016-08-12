#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=30;
int T,n;
int g[maxn][maxn],in[maxn],out[maxn],vis[maxn];
void dfs(int u){
    vis[u]=1;
    for(int i=0;i<maxn;i++)
        if(g[u][i]&&!vis[i]) dfs(i);
}

int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    cin>>T;
    while(T--){
        scanf("%d",&n);
        char s[1005];
        memset(g,0,sizeof(g));
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%s",s);
            ++g[s[0]-'a'][s[strlen(s)-1]-'a'];
            ++out[s[0]-'a'];
            ++in[s[strlen(s)-1]-'a'];
        }
        
        int flag=1,c1=0,c2=0;
        for(int i=0;i<maxn;i++){
            if(in[i]!=out[i]){
                if(in[i]==out[i]+1) c1++;
                else if(out[i]==in[i]+1) c2++;
                else { flag=0; break; }
            }
        }
        if(c1&&c2&&c1+c2>2) flag=0;
        
        if(flag){
            for(int i=0;i<maxn;i++){
                if(out[i]){
                    dfs(i);
                    break;
                }
            }
            for(int i=0;i<maxn;i++)
                if(!vis[i]&&(in[i]||out[i])) flag=0;
        }
        printf("%s\n",flag?"Ordering is possible.":"The door cannot be opened.");
    }
    return 0;
}
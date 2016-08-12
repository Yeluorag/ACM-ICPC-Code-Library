#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

char s[205];
int g[30][30],flag[100],has[30],ans,a[10],ret[10];


int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(gets(s)){
        if(s[0]=='#') break;
        memset(has,0,sizeof(has));
        memset(g,0,sizeof(g));
        memset(flag,0,sizeof(flag));
        int len=strlen(s),vis=0,u,num=0;
        for(int i = 0; i < len; i++) {
            if(s[i] >= 'A' && s[i] <= 'Z')
                flag[s[i]-'A'] = 1;
            if(s[i] == ':'){
                u=s[i-1]-'A';
                vis=1;
            }
            else if(vis&&s[i]>='A'&&s[i]<='Z')
                g[s[i]-'A'][u] = g[u][s[i]-'A'] = 1;
            else if(s[i]==';') vis= 0;
        }
        for(int i = 0; i < 26; i++) if(flag[i]) a[num++] = i;
       
        ans=100;
        do{
            int res=-1;
            for(int i=0;i<num;i++){
                for(int j=i+1;j<num;j++){
                    if(g[a[i]][a[j]]) res=max(res,j-i);
                }
                if(res>ans)break;
            }
//            for(int i=0;i<num;i++) printf("%c ",a[i]+'A');
//            printf("-> %d\n",res);
            if(ans>res){
                ans=res;
                memcpy(ret,a,sizeof(a));
            }
        }while(next_permutation(a,a+num));
//        search(0,-1);
        for(int i=0;i<num;i++) printf("%c ",ret[i]+'A');
        printf("-> %d\n",ans);
        
        
    }    
    return 0;
}
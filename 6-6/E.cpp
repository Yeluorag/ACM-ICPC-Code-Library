#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef  long long  ll;
const int INF=0x3f3f3f3f;
typedef pair<int,int> PII;
int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
int step[362880],T,cas=0;
int St[10]={1,2,3,4,5,6,7,8,9},goal[10],to[12];
int dir[12][9]={
    {1,2,0,3,4,5,6,7,8},
    {0,1,2,4,5,3,6,7,8},
    {0,1,2,3,4,5,7,8,6},
    {6,1,2,0,4,5,3,7,8},
    {0,7,2,3,1,5,6,4,8},
    {0,1,8,3,4,2,6,7,5},
    {2,0,1,3,4,5,6,7,8},
    {0,1,2,5,3,4,6,7,8},
    {0,1,2,3,4,5,8,6,7},
    {3,1,2,6,4,5,0,7,8},
    {0,4,2,3,7,5,6,1,8},
    {0,1,5,3,4,8,6,7,2},
};
// 康托双射函数
int Cantor(int s[],int n){
    int code=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i+1;j<n;j++){
            if(s[i]>s[j])cnt++;
        }
        code+=(cnt*fac[n-i-1]);
    }
    return code;
}

void invCantor(int ans[],int n,int k){
    int vis[20]={0};
    int i,j,t;
    for(i=0;i<n;i++){
        t=k/fac[n-i-1];
        for(j=1;j<=n;j++)if(!vis[j]){if(t==0)break;t--;}
        ans[i]=j,vis[j]=true;
        k%=fac[n-i-1];
    }
}

void bfs(int st[]){
    memset(step,0x3f,sizeof(step));
    int s=Cantor(st,9);
    int temp[12],curs,curstep;
    queue<PII >que;
    step[s]=0;
    que.push(PII(s,0));
    while(!que.empty()){
        PII pp=que.front();que.pop();
        s=pp.first;
        curstep=pp.second+1;
        invCantor(st,9,s);					//s反向康托求原序列
        for(int i=0;i<12;i++){
            for(int j=0;j<9;j++) temp[j]=st[dir[i][j]];
            curs=Cantor(temp,9);
            if(step[curs]==INF){
                step[curs]=curstep;
                que.push(PII(curs,curstep));
            }
        }
    }
}

bool vis[11];
vector<int>notapper;
vector<int>staridx;

int main(){
     // freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    bfs(St);
    cin>>T;
    while(cas<T){
        notapper.clear();
        staridx.clear();
        memset(vis,0,sizeof(vis));

        for(int i=0;i<9;i++){
            scanf("%d",&St[i]);
            to[St[i]]=i+1;			//映射
        }
        char c[2];
        for(int i=0;i<9;i++){
            scanf("%s",c);
            if(c[0]!='*')goal[i]=to[c[0]-'0'],vis[goal[i]]=1;
            else staridx.push_back(i);
        }
        for(int i=1;i<=9;i++)if(!vis[i])notapper.push_back(i);	//可能是*的数字
        sort(notapper.begin(),notapper.end());
        int len=staridx.size();
        int ans=INF;
        do{
            for(int i=0;i<len;i++){
                int idx=staridx[i];
                goal[idx]=notapper[i];
            }
            int tmp=Cantor(goal,9);
            ans=min(ans,step[tmp]);
        }while(next_permutation(notapper.begin(),notapper.end()));
        printf("Case #%d: ",++cas);
        if(ans==INF)printf("No Solution!\n");
        else printf("%d\n",ans);
    }
    return 0;
}


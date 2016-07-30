#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int n,k1,k2,m,ans=0,t1,t2,flag=0;
queue<int> a,b;
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    scanf("%d%d",&n,&k1);
    rep(i,k1){scanf("%d",&m);a.push_back(m);}
    scanf("%d",&k2);rep(i,k2){scanf("%d",&m);b.push_back(m);}
    t1=k1;t2=k2;
    while(ans<1000000){
    	if(!t1){flag=2;break;}
    	if(!t2){flag=1;break;}
    	int aq,bq;
    	aq=a.front();bq=b.front();
    	a.pop();b.pop();
    	if(aq>bq){
    		t1+=1;t2--;
    		a.push_back(bq);
    		a.push_back(aq)''
    	}else{
    		t2+=1;t1--;
    		b.push_back(aq);
    		b.push_back(bq);
    	}
    	ans++;
    }
    if(flag)printf("%d %d\n",ans,flag);
    else printf("-1\n");
    return 0;
}

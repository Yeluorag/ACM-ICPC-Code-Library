#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1<<30;

int n,m,ans,first;
int d[12][105],nxt[12][105],a[12][105];
int dir[3]={-1,0,1};
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d",&m,&n)!=EOF){
    	ans=INF;first=0;
    	for(int i=0;i<m;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
    	for(int j=n-1;j>=0;j++){
    		for(int i=0;i<m;i++){
    			if(j==n-1)d[i][j]=a[i][j];
    			else{
    				if(i==0) dir[0]=m-1;
    				if(i==m-1)dir[2]=0;
    				sort(dir,dir+3);
    				d[i][j]=INF;
    				for(int k=0;k<3;k++){
    					if(d[i+dir[k]][j+1]+a[i][j]<d[i][j]){
    						d[i][j]=d[i+dir[k]][j+1]+a[i][j];
    						nxt[i][j]=i+dir[k];
    					}
    				}
    				if(d[i][j]<ans){
    					ans=d[i][j];
    					first=i;
    				}
    			}
    		}
    	}
    	for(int i=0;i<n-1;i++){
    		printf("%d ",first);
    		first=nxt[first][i];
    	}
    	printf("%d\n%d\n",first,ans);
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int T,n,ans,sum,mid;
int flag[1005];
struct point{
	int x,y;
}p[1005];
bool cmp(point a,point b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}

int main(){
    freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    cin>>T;
    while(T--){
    	sum=0;
    	ans=1;
    	memset(flag,0,sizeof(flag));
    	scanf("%d",&n);
    	for(int i=0;i<n;i++) {
    		scanf("%d%d",&p[i].x,&p[i].y);
    		sum+=p[i].x;
    	}
    	sort(p,p+n,cmp);
    	if(n%2) mid=p[n/2].x;
    	else mid=sum/n;
    	for(int i=0;i<n;i++){
    		int temp=1;
    		for(int j=i+1;j<n;j++){
    			if((p[i].x+p[j].x==2*ans)&&(p[i].y=p[j].y)){
    				temp=0;
    				flag[i]=1;
    				break;
    			}
    		}
    		if(temp){ans=0;break;}
    	}
    	printf("%s\n",ans?"YES":"NO");
    }
    return 0;
}

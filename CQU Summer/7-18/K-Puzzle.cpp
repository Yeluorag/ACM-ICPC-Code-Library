#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char maz[6][6],cmd[1005];
int mz[6][6],x,y,ans,cas=0;
int main(){
    // freopen("/Users/apple/input.txt","r",stdin);
 //	freopen("/Users/apple/out.txt","w",stdout);
    while(gets(maz[0])){
    	if(maz[0][0]=='Z')break;ans=1;
    	for(int i=1;i<5;i++) gets(maz[i]);
    	for(int i=0;i<5;i++){
    		for(int j=0;j<5;j++){
    			if(maz[i][j]==' ') {
    				mz[i][j]=-1;
    				x=i;
    				y=j;
    			}
    			else mz[i][j]=maz[i][j]-'A';
    		}
    	}
    	int idx=0;
    	while(~scanf("%c",&cmd[idx++])){if(cmd[idx-1]=='0')break;}
    	getchar();
    	for(int i=0;i<idx-1;i++){
    		int tx,ty;
    		switch(cmd[i]){
    			case 'A':tx=x-1;ty=y;break;
    			case 'B':tx=x+1;ty=y;break;
    			case 'L':tx=x;ty=y-1;break;
    			case 'R':tx=x;ty=y+1;break;
    		}
    		if(tx<0||tx==5||ty<0||ty==5){ans=0;break;}
    		swap(mz[tx][ty],mz[x][y]);
    		x=tx;y=ty;
    	}
    	if(cas)puts("");
    	printf("Puzzle #%d:\n",++cas);
    	if(!ans) {printf("This puzzle has no final configuration.\n");continue;}
    	for(int i=0;i<5;i++){
    		for(int j=0;j<5;j++){
    			if(mz[i][j]==-1)printf(" ");
    			else printf("%c",mz[i][j]+'A');
    			if(j<4) printf(" ");
    		}
    		puts("");
    	}
    }
    return 0;
}

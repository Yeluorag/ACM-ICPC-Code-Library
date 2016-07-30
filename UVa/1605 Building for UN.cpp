#include <iostream>
#include <cstdio>
using namespace std;

int n;
char maz[2][55][55];
char nation[55];

int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    for(int i=0;i<52;i++) nation[i]=i<26?'A'+i:'a'+i-26;
    while(scanf("%d",&n)!=EOF){
    	for(int i=0;i<2;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)maz[i][j][k]='\0';
	    for(int i=0;i<n;i++)for(int j=0;j<n;j++)maz[0][i][j]=nation[i];
	    for(int i=0;i<n;i++)for(int j=0;j<n;j++)maz[1][j][i]=nation[i];
	    printf("%d %d %d\n",2,n,n);
	    for(int i=0;i<n;i++)printf("%s\n",maz[0][i]);
	    cout<<endl;
	    for(int i=0;i<n;i++)printf("%s\n",maz[1][i]);
	}
    return 0;
}
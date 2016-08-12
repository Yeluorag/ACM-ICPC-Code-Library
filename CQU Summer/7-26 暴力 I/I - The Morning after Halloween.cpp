#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int w,h,n,ans;
int s[3][2],e[3][2];
char maz[20][20];
struct node{
	int pos[6];
};

void bfs(){
	node st,ed;
	for(int i=0;i<2*n;i++) {
		st.pos[i]=s[i/2][i%2];
		ed.pos[i]=e[i/2][i%2];
	}
	queue<node>que;
	que.push(st);
	que.push(ed);
	while(!que.empty()){
		
	}
}
int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d%d%d",&w,&h,&n)!=EOF){
    	if(!w&&!h&&!n) break;
    	for(int i=0;i<w;i++) gets(maz[i]);
    	for(int i=0;i<w;i++){
    		for(int j=0;j<h;j++){
    			char c=maz[i][j];
    			if(c>='A'&&c<='C'){
    				e[c-'A'][0]=i;
    				e[c-'A'][1]=j;
    			}else if(c>='a'&&c<='c'){
    				s[c-'a'][0]=i;
    				s[c-'a'][1]=j;
    			}
    		}
    	}
    }
    return 0;
}
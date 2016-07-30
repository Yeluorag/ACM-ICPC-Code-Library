#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct  node{
	double l,r;
	node(double ll,double rr){l=ll;r=rr;}
};

vector<node> nd[55];
int T,s,f[50];
double r,w[10]；
int main(){
	cin>>T;
	while(T--){
		memset(f,0,sizeof(f));
		scanf("%lf%d",&r,&s);
		for(int i=0;i<s;i++)scanf("%d",&w[i]);
			
	}
	return 0;
}
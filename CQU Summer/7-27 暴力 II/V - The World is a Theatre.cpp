#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

ll N,M,T;
ll comb[40][40];
ll res;

int main(){
	freopen("/Users/apple/input.txt","r",stdin);
	cin >> N >> M >> T;
	
	for(int i=1;i<40;i++)
		for(int j=0;j<40;j++){
			if(j>i)
				comb[i][j]=0;
			else if(!j || i==j)
				comb[i][j]=1;
			else if(j==1 || j==i-1)
				comb[i][j]=i;
			else
				comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
		}
		
	for(int i=4;i<=N && i<T;i++)
		if(T-i<=M)
			res+=comb[N][i]*comb[M][T-i];
	
	cout << res << endl;
	
	return 0;
}
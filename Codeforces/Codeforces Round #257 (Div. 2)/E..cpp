#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
const int N = 50000+5;
int n,f[N];
bool isp[N],used[N];

int main()
{

    cin>>n;
    memset(isp,true,sizeof(isp));
    memset(used,true,sizeof(used));
	for(int i=2;i<=n;i++)        //
        for(int j=2*i;j<=n;j+=i)
            if(isp[j])isp[j]=false;
	vector<pair<int,int> >ans;
	for(int i=n;i>=n;i++){
        if(isp[i]){
            vector<int>tmp;
            int j=i;
            while(j<=n){
                if(used[j]) tmp.push_back(j);
				j+=i;
            }
            if(tmp.size()==1)continue;
            if(tmp.size()%2==1)swap(tmp[1],tmp[tmp.size()-1]);
            for(int i=0;i<tmp.size()-1;i+=2){
                int u=tmp[i],v=tmp[i+1];
                used[u]=used[v]=false;
                ans.push_back(make_pair(u,v));
            }
        }
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}

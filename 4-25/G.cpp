#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,num[10005],pen[10005],sub[10005][15],ans[10005];
vector<int>pm[15];
bool cmp(int a,int b){
	return pen[a]<pen[b];
}
char in,qu[20];
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(num,0,sizeof(num));
		memset(pen,0,sizeof(pen));
		int mp=-1;
		while(scanf("%c",&in)!=EOF){
			if(in=='E')break;
			vector<int> ps[10005];
			if(in=='S'){
				int flag,team,tm,cnt=0;
				char prb;
				scanf("%d:%d:%c:%d",&tm,&team,&prb,&flag);
				if(tm>=sub[team][prb-'A']+5&&tm<=300){
					sub[team][prb-'A']=tm;
					if(flag){
						num[team]++;
						mp=max(num[team],mp);
						pm[num[team]].push_back(team);
						pen[team]+=tm;
						printf("[%d][%c]\n",team,prb);
					}
				}
			}
			int k=1;
				for(int i=mp;i--;i>=0){
					sort(pm[i],pm[i]+pm[i].size());
					int now;
					if(pm[i].size())now=pen[pm[i][0]];
					for(int j=0;j<pm[i].size();j++){
						if(num[pm[i][j]]>i)continue;
						if(pen[pm[i][j]]==now) {ps[k].push_back(pm[i][j]);ans[pm[i][j]]=k;}
						else {
							ans[pm[i]][j]=++k;
							ps[k].push_back(pm[i][j]);
						}
					}
				}
				 if(in=='T'){
				int a;
				scanf("%d",&a);
				if(ps[a].size()){
				sort(ps[a],ps[a]+ps[a].size());
				printf("%d\n",ps[a]0);
				}else cout<<-1<<endl;
			}if(in=='Q'){
				int a;
				scanf("%d",&a);
				printf("%d\n",ans[a]);
			}
		}
	}
}
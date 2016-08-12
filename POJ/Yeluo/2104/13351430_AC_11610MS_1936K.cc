#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

#define For(i,n) for(int i=0;i<n;i++)
using namespace std;

const int MAX_N=100005;
const int B=1000;
int A[MAX_N],I[MAX_N],J[MAX_N],K[MAX_N],
        nums[MAX_N],n,m;
vector<int> bucket[MAX_N/B];

int main()
{
    scanf("%d%d",&n,&m);
    For(i,n){
        scanf("%d",&A[i]);
        bucket[i/B].push_back(A[i]);
        nums[i]=A[i];
    }
    For(i,m){
		scanf("%d%d%d",&I[i],&J[i],&K[i]);
		I[i]--;
		J[i]--;
	}
    sort(nums,nums+n);
    For(i,n/B)sort(bucket[i].begin(),bucket[i].end());
    For(i,m){
        int l=I[i],r=J[i]+1,k=K[i]; 
        int lb=-1,ub=n-1;
        while(ub-lb>1){
            int mid=(lb+ub)/2;
            int x=nums[mid];
            int tl=l,tr=r,c=0;
            while(tl<tr&&tl%B!=0)if(A[tl++]<=x)c++;
            while(tl<tr&&tr%B!=0)if(A[--tr]<=x)c++;
            while(tl<tr){
                int b=tl/B;
                c+=upper_bound(bucket[b].begin(),bucket[b].end(),x)-bucket[b].begin();
                tl+=B;
            } 
            if(c>=k) ub=mid;
            else lb=mid;
        }
        printf("%d\n",nums[ub]);
    }
    return 0;
}

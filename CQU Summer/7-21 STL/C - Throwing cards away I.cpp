#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,card[1005];
int main(){
//    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
    while(scanf("%d",&n),n){
        int cnt=n,top=0,bot=n-1;
        memset(card,0,sizeof(card));
        for(int i=0;i<n;i++) card[i]=i+1;
        printf("Discarded cards:");
        while(cnt>1){
            printf(" %d",card[top++]);
            card[++bot]=card[top++];
            cnt--;
            if(cnt>1)printf(",");
        }
        printf("\nRemaining card: %d\n",card[top]);
    }
    return 0;
}

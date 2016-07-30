#include <iostream>
#include <cstdio>
using namespace std;

int n,m;
char N[30],M[30];

bool C(char a,char b){
    if((a=='>'&&b=='v')||
        (a=='<'&&b=='^'))
            return true;
    return false;
}
int main()
{
    int flag=1;
    freopen("D:\\input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        cin>>N[i];
    for(int i=0;i<m;i++)
        cin>>M[i];
    if(C(N[0],M[0])||C(N[0],M[m-1])||C(N[n-1],M[0])||C(N[n-1],M[m-1]))flag=0;
    printf("%s",flag?"YES":"NO");
    return 0;
}

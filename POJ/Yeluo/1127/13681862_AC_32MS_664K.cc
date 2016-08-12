#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX=10005;
const double EPS=1e-10;

double add(double a,double b)
{
    if(abs(a+b)<EPS*(abs(a)+abs(b))) return 0;
    return a+b;
}

struct P{
    double x,y;
    P(){};
    P(double x,double y):x(x),y(y){};
    P operator + (P p){return P(add(x,p.x),add(y,p.y));
    }
    P operator - (P p){return P(add(x,-p.x),add(y,-p.y));
    }
    P operator * (double d){return P(x*d,y*d);
    }
    double dot(P p){return add(x*p.x,y*p.y);
    }
    double det(P p){return add(x*p.y,-y*p.x);
    }
};

bool on_seg(P p1,P p2,P q){
    return (p1-q).det(p2-q)==0&&(p1-q).dot(p2-q)<=0;
}
P cal(P p1,P p2,P q1,P q2){
    return p1+(p2-p1)*((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}
int n,m,a,b;
double l1,l2,r1,r2;
bool g[20][20];
P p[20],q[20];
int main()
{
	//freopen("d:\\input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF){
		if(n==0)break;
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&l1,&r1,&l2,&r2);
            p[i].x=l1;
            p[i].y=r1;
            q[i].x=l2;
            q[i].y=r2;
        }
        
        for(int i=0;i<n;i++){
            g[i][i]=true;
            for(int j=0;j<i;j++){
                if((p[i]-q[i]).det(p[j]-q[j])==0){
                    g[i][j]=g[j][i]=on_seg(p[i],q[i],p[j])||
                                    on_seg(p[i],q[i],q[j])||
                                    on_seg(p[j],q[j],p[i])||
                                    on_seg(p[j],q[j],q[i]);
					//printf("g[%d][%d]=%s\n",i,j,g[i][j]?"true":"false");
                }else{
                    P c=cal(p[i],q[i],p[j],q[j]);
                    g[i][j]=g[j][i]=on_seg(p[i],q[i],c)&&on_seg(p[j],q[j],c);
                }
            }
        }
        for(int k=0;k<n;k++){
             for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    g[i][j]|=g[i][k]&&g[k][j];
                }
            }
        }
        while(true){
			scanf("%d%d",&a,&b);
			if(a==0&&b==0)break;
            puts(g[a-1][b-1]?"CONNECTED":"NOT CONNECTED");
        }
    }
    return 0;
}

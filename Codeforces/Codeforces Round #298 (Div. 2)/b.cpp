//
//  GCJ b.cpp
//  ACM
//
//  Created by I‘m a Mac on 15-4-12.
//  Copyright (c) 2015年 Yeluo's Game Maze. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    freopen("/Users/apple/input.txt","r",stdin);
    int v1,v2,t,d,ans=0,l,r,res,dt,a,b,p;
    cin>>v1>>v2;
    cin>>t>>d;
    a=min(v1,v2);b=max(v1,v2);
    res=b-a;
    if(d>0){
        if(res>0)dt=res/d+1;
        else dt=0;
        l=(t-1+dt)/2;r=t-1-l;p=a;
        if (r>0) {
            ans+=a+(2*p+l*d)*(l-1)/2;
            ans+=(2*b+(r-2)*d)*(r-1)/2;
            p+=(l-1)*d;
            if((t-1+dt)%2) {
                p+=d;
                ans+=p;
                if(res>0||t==2)p-=res%d;
                else p-=d;
                ans+=p;
            }else {
                if(res>0||t==2)p+=res%d;
                else p+=d;
                ans+=p;
                p-=d;ans+=p;
            }
        }else ans=(2*a+(t-2)*d)*(t-1)/2+b;
    }else	ans=t*a;
    printf("%d\n",ans);
    return 0;
}

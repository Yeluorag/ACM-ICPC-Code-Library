//
//  1005 Number Sequence.cpp
//  ACM
//
//  Created by I‘m a Mac on 15-1-2.
//  Copyright (c) 2015年 Yeluo's Game Maze. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
const int mod=7;

mat mul(mat &A,mat &B){
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++){
        for(int k=0;k<A[0].size();k++){
            for(int j=0;j<B[0].size();j++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
            }
        }
    }
    return C;
}

mat pow(mat C,int m){
    mat X(C.size(),vec(C.size()));
    for(int i=0;i<X.size();i++){
        X[i][i] = 1;
    }
    while(m){
        if(m&1) X=mul(X,C);
        C=mul(C,C);
        m>>=1;
    }
    return X;
}
int a,b,n;
int main() {
    //freopen("/Users/apple/Documents/input.txt","r",stdin);
    while(scanf("%d%d%d",&a,&b,&n),a,b,n){
        mat A(2,vec(2));
        A[0][0]=a;A[0][1]=b;
        A[1][0]=1;A[1][1]=0;
        A=pow(A,n-1);
        printf("%d\n",(A[1][0]+A[1][1])%mod);
    }
    return 0;
}

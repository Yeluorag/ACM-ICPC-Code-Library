struct Mat {  
    LL matrix[sz][sz];  
};
Mat I, A, K, A0;    
const int sz = 2;  
Mat Add(Mat a, Mat b) {  
    Mat c;  
    rep(i, sz) rep(j, sz) 
        c.matrix[i][j] = (a.matrix[i][j] + 
                        b.matrix[i][j]) % M;  
    return c;  
}  
  
Mat Mul(Mat a, Mat b) {  
    Mat c;  
    rep(i, sz) {  
        rep(j, sz) {  
            c.matrix[i][j] = 0;  
            rep(k, sz) {  
                c.matrix[i][j] += (a.matrix[i][k] * 
                                 b.matrix[k][j]) % M;  
                c.matrix[i][j] %= M;  
            }  
        }  
    }  
    return c;  
}  
  
Mat Pow(Mat a, LL x) {  
    Mat ret = I;  
    while(x > 0) {  
        if(x & 1) ret = Mul(ret, a);  
        a = Mul(a, a);  
        x >>= 1;  
    }  
    return ret;  
}  
// 计算 a^1 + a^2 + a^3 + ... + a^x
Mat Work(Mat a, LL x) {  
    if(x == 1) 
        return a;  
    else if(x & 1) 
        return Add(Pow(a, x), Work(a, x - 1));  
    else return Mul(Work(a, x >> 1), 
                 Add(Pow(a, x >> 1), I));  
}  
// 单位矩阵初始化  
Mat Init_I() {  
    Mat ret;  
    rep(i, sz) rep(j, sz) ret.matrix[i][j] = i == j;  
    return ret;  
}  
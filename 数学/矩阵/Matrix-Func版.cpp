struct Mat {
    LL matrix[sz][sz];
};
const int sz = 2;
Mat Add(Mat a, Mat b) {
    Mat c;
    rep(i, sz) rep(j, sz) c.matrix[i][j] = (a.matrix[i][j] + b.matrix[i][j]) % M;
    return c;
}

Mat Mul(Mat a, Mat b) {
    Mat c;
    rep(i, sz) {
        rep(j, sz) {
            c.matrix[i][j] = 0;
            rep(k, sz) {
                c.matrix[i][j] += (a.matrix[i][k] * b.matrix[k][j]) % M;
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

Mat Init_I() {
    Mat ret;
    rep(i, sz) rep(j, sz) ret.matrix[i][j] = i == j;
    return ret;
}
struct matrix{
    int N; long long A[82][82];
    Matrix(int n){
        N = n;
        for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) A[i][j] = 0;
    }
    
    Matrix operator +(Matrix t){
        Matrix res(N);
        for (int i = 0; i < N; i ++) for (int j = 0; j < N; j ++) res.A[i][j] = (A[i][j] + t.A[i][j]) % mod;
        return res;
    }

    Matrix operator *(Matrix t){
        Matrix res(N);
        for (int i = 0; i < N; i ++) for (int j = 0; j < N; j ++) for (int k = 0; k < N; k ++) res.A[i][j] = (res.A[i][j] + A[i][k] * t.A[k][j]) % mod;
        return res;
    }
};
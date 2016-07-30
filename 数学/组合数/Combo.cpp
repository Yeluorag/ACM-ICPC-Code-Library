LL C[N][N];
void Combo() {
	mem(C, 0);
	for(int i = 0; i < N; i ++) {
		C[i][0] = 1;
		for(int j = 1; j <= i; j ++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
}
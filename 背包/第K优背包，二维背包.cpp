// Use Last Group
void ZeroOne_Pack(int weight, int value, int m) {
	for(int i = m; i >= weight; i --)
		dp[i] = max(dp[i], dp[i-weight] + value);
}
// Use This Group
void Complete_Pack(int weight, int value, int m) {
	for(int i = weight; i <= m; i ++)
		dp[i] = max(dp[i], dp[i-weight] + value);
}
// n: Number of Group, m: Total Weight of Pack
void Multi_Pack(int w[], int v[], int num[], int n, int m) {
	mem(dp, 0);
	for(int i = 1; i <= n; i ++) {
		if(num[i] * w[i] > m)
			Complete_Pack(w[i], v[i], m);
		else {
			for(int k = 1; k < num[i]; k *= 2) {
                ZeroOne_Pack(k * w[i], k * v[i], m);
                num[i] -= k;
            }
			ZeroOne_Pack(num[i] * w[i], num[i] * v[i], m);
		}
	}
}
// m: Number of Limited count, l: Total Weight of Pack
void TwoDimension_ZeroOne_Pack(int w[], int v[], int n, int m, int l) {
	mem(dp[0], 0);
	for(int i = 1; i <= n; i ++) for(int j = 0; j <= l; j ++) dp[i][j] = - inf;
	for(int i = 1; i <= n; i ++) {
		for(int j = m; j >= 1; j --) {
			for(int k = l; k >= w[i]; k --) {
				dp[j][k] = max(dp[j][k], dp[j-1][k-w[i]] + v[i]);
			}
		}
	}
}
// K: Kth Maximum Value of Pack, If Total Kinds Less than K, put zero
void Kth_ZeroOnePack(int w[], int v[], int n, int m, int K) {
	mem(dp, 0);
	int A[35], B[35], a, b, c;
	FOR(i, 1, n) {
		for(int j = m; j >= w[i]; j --) {
			FOR(k, 1, K) {
				A[k] = dp[j-w[i]][k] + v[i];
				B[k] = dp[j][k];
			} A[K+1] = B[K+1] = -1;
			a = b = c = 1;
			while(c <= K && (A[a] + B[b] > -2)) {
				if(A[a] > B[b]) dp[j][c] = A[a], a ++;
				else dp[j][c] = B[b], b ++;
				if(dp[j][c] != dp[j][c-1]) c ++;
			}
		}
	}
}
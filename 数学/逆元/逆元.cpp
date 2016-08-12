void exgcd(int a, int b, int &d, int &x, int &y) {
	if(!b) { d = a; x = 1; y = 0; }
	else { exgcd(b, a%b, d, y, x); y -= x * (a / b); }
}
// 求解得到x为a对m取模的逆元
// 若m为素数，可用费马小定理直接求出逆元
void solve() {
	int a, m, d, x, y;
	exgcd(a, m, d, x, y);
	// OR
	x = quick_mod(a, m - 2, m);
}

// 求1~p模p的所有逆元，其中p为奇质数.
void solve() {
	for(int i = 2; i < N; i ++) {
		if(i >= M) break;
		inv[i] = (M - M / i) * inv[M % i]  % i;
	}
}
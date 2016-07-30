void exgcd(int a, int b, int &d, int &x, int &y) {
	if(!b) { d = a; x = 1; y = 0; }
	else { exgcd(b, a%b, d, y, x); y -= x * (a / b); }
}
// n为a[]大小.
// x = a[i] (mod m[i]), 求解返回x
int CRT(int a[], int m[], int n) {
	int M = 1, ans = 0;
	for(int i = 0; i < n; i ++) M *= m[i];
	for(int i = 0; i < n; i ++) {
		int x, y, d;
		int Mi = M / m[i];
		exgcd(Mi, m[i], d, x, y);
		ans = (ans + Mi * x * a[i]) % M;
	}
	if(ans < 0) ans += M;
	return ans;
}
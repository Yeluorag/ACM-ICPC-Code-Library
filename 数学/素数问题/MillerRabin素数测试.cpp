// N 为测试次数
LL random(LL n) {
	return (LL)((double)rand() / RAND_MAX * n + 0.5);
}

LL multi_mod(LL a, LL b, LL m) {
	LL ret = 0;
	a %= m;
	while(b > 0) {
		if(b & 1) ret = (ret + a) % m;
		a = (a + a) % m;
		b >>= 1;
	}
	return ret;
}

LL quick_mod(LL a, LL b, LL m) {
	LL ret = 1;
	a %= m;
	while(b > 0) {
		if(b & 1) ret = ret * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return ret;
}

bool Miller_Rabin(LL n) {
	if(n == 2) return true;
	if(n < 2 || !(n & 1)) return false;
	LL m = n - 1;
	int k = 0;
	while((m & 1) == 0) {
		k ++;
		m >>= 1;
	}
	for(int i = 0; i < N; i ++) {
		LL a = rand() % (n - 1) + 1;
		LL x = quick_mod(a, m, n);
		LL y = 0;
		rep(j, k) {
			y = multi_mod(x, x, n);
			if(y == 1 && x != 1 && x != n - 1) return false;
			x = y;
		}
		if(y != 1) return false;
	}
	return true;
}


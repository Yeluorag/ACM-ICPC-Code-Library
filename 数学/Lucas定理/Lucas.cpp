// 预处理的Lucas模板
LL fac[N];
LL Quick_mod(LL a, LL b, LL p) {
	 LL ret = 1;
	 a %= p;
	 while(b > 0) {
	 	if(b & 1) ret = ret * a % p;
	 	b /= 2;
	 	a = a * a % p;
	 }
	 return ret;
}

void init(LL p) {
	fac[0] = 1;
	FOR(i, 1, p) fac[i] = fac[i - 1] * i % p;
}

LL Cm(LL n, LL m, LL p) {
	if(m > n) return 0;
	return fac[n] * Quick_mod(fac[m] * fac[n - m] % p, p - 2, p) % p;
}

LL Lucas(LL n, LL m, LL p) {
	if(!m) return 1;
	return Cm(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

// 没有预处理
LL Quick_mod(LL a, LL b, LL p) {
	 LL ret = 1;
	 a %= p;
	 while(b) {
	 	if(b & 1) ret = ret * a % p;
	 	b >>= 1;
	 	a = a * a % p;
	 }
	 return ret;
}

// Cm(n, m) = n! / (n - m)! * (b!)^(p-2)
LL C(LL n, LL m, LL p) {
	if(m > n) return 0;
	LL ret = 1;
	for(int i = 1; i <= m; i ++) {
		LL a = (n + i - m) % p;
		LL b = i % p;
		ret = ret * (a * Quick_mod(b, p - 2) % p) % p;
	}
	return ret;
}

// Lucas(n, m) = Cm(n % p, m % p) * Lucas(n / p, m / p) % p;
LL Lucas(LL n, LL m, LL p) {
	if(!m) return 1;
	return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

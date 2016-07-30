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
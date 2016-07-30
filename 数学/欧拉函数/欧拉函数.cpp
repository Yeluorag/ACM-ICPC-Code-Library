int phi[N];
int Euler_Phi(int n) {
	int ret = n, m = (int)sqrt(n + 0.5);
	for(int i = 2; i <= m; i ++) if(n % i == 0) {
		ret = ret / i * (i - 1);
		while(n % i == 0) n /= i;
	} if(n > 1) ret = ret / n * (n - 1);
	return ret;
}

void Phi_Table(int n, int * phi) {
	mem(phi, 0);
	phi[1] = 1;
	for(int i = 2; i <= n; i ++) {
		if(!phi[i]) {
			for(int j = i; j <= n; j += i) {
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}


// inv[i]为i模MOD的逆元，C为组合数，B为伯努利数.
// 伯努利数可用于快速求幂和  sum(1->n)i^k = (1 / (k + 1)) * sum(1->n)C[k+1][i]*B[k+1-i] * (n + 1)^i.
// 伯努利数满足 sum(0->n)C[n+1][i]*B[i] = 0.
// 则B[n] = (-1 / (n + 1)) * (C[n+1][0] * B[0] + C[n+1][1] * B[1] + ... + C[n+1][n-1] * B[n-1]).
LL C[N][N], B[N], inv[N];
void Combo() {

    for(int i = 0; i < N; i ++) {
        C[i][0] = C[i][i] = 1;
        if(i == 0) continue;
        for(int j = 1; j < i; j ++)
            C[i][j] = (C[i-1][j-1] % MOD + C[i-1][j] % MOD) % MOD;
    }
}
void Bernoulli() {
    Combo();
    inv[1] = 1;
    for(int i = 2; i < N; i ++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    B[0] = 1;
    for(int i = 1; i < N - 1; i ++) {
        LL ans = 0;
        for(int j = 0; j < i; j ++) {
            ans += C[i + 1][j] * B[j];
            ans %= MOD;
        }
        ans *= -inv[i + 1];
        ans = (ans % MOD + MOD) % MOD;
        B[i] = ans;
    }
}
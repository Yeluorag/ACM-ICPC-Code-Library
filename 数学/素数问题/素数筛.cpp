// 素数筛，找出N以内所有素数。vis[i] == 1 则i为合数.
vector<int> primes;
bool vis[N];
void Primes_Init() {
    int m = sqrt(n + 0.5);
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i <= m; i ++) if(!vis[i])
        for(int j = i * i; j <= n; j += i) vis[j] = 1;
    for(int i = 2; i <= n; i ++) if(!vis[i]) primes.push_back(i);
}
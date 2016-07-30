// 题意：求出桥数，然后有Q次填边，每次填边后输出剩余的桥数。
int dfn[N], low[N], fa[N], head[N];
bool brige[N], vis[N];  
struct edge {  
    int v, next;  
}e[4 * N];  
int brigeNum = 0, ne = 0, dfsNum = 0;  
void addEdge(int u, int v) {  
    e[ne].v = v;  
    e[ne].next = head[u];  
    head[u] = ne ++;  
}  
// Imp  
void init() {  
    mem(dfn, 0);  
    mem(low, 0);  
    mem(fa, -1);  
    mem(vis, 0);  
    mem(brige, 0);  
    mem(head, -1);  
    dfsNum = ne = brigeNum = 0;  
}  
  
void Tarjan(int u, int f) {  
    dfn[u] = low[u] = ++ dfsNum;  
    for(int i = head[u]; i != -1; i = e[i].next) {  
        int v = e[i].v;  
        if(!dfn[v]) {  
            vis[v] = 1;  
            fa[v] = u;  
            Tarjan(v, u);  
            low[u] = min(low[u], low[v]);  
            if(dfn[u] < low[v]) {  
                brigeNum ++;  
                brige[v] = 1;  
            }  
        } else if(v != f) low[u] = min(low[u], dfn[v]);  
    }  
}  
  
void work(int u) {  
    if(brige[u]) brigeNum --, brige[u] = 0;  
}  
  
void LCA(int u, int v) {  
    if(dfn[u] > dfn[v]) swap(u, v);  
    while(dfn[u] < dfn[v]) {  
        work(v);  
        v = fa[v];  
    }  
    while(v != u) {  
        work(u);  
        work(v);  
        u = fa[u], v = fa[v];  
    }  
}  
  
int main(){  
#ifdef LOCAL  
    freopen("/Users/apple/input.txt", "r", stdin);  
//  freopen("/Users/apple/out.txt", "w", stdout);  
#endif  
      
    while(sii(n, m) != EOF, n + m) {  
        init();  
        int u, v;  
        rep(i, m) {  
            sii(u, v);  
            addEdge(u, v), addEdge(v, u);  
        }  
        FOR(i, 1, n + 1) fa[i] = i;  
        Tarjan(1, -1);  
        printf("Case %d:\n", ++ cas);  
        si(q);  
        rep(i, q) {  
            sii(u, v);  
            LCA(u, v);  
            printf("%d\n", brigeNum);  
        } puts("");  
    }  
    return 0;  
}  
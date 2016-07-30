/*
n个点m条无向边，要去一条边得到两个连通分支，所以要去掉的一定是桥。
先跑一边Tarjan找到所有的桥，然后双连通缩点，
所有的双连通分量所成一个点，再用桥连接，得到一棵树。然后跑一遍树形DP。
*/
int n, m, ne, ans, all, top, bch, dfsNum;  
int a[N], head[N], dfn[N], low[N], tree[N], sum[N], col[N], stack[N];  
vector<pair<int, int> > brige;  
bool vis[N];  
struct edge {  
    int v, next;  
}e[10 * N];  
// Imp  
void addEdge(int u, int v) {  
    e[ne].v = v, e[ne].next = head[u], head[u] = ne ++;  
}  
  
void Tarjan(int u, int fa) {  
    dfn[u] = low[u] = dfsNum ++;  
    vis[u] = 1;  
    stack[top++] = u;  
    int flag = 0;  
    for(int i = head[u]; i != -1; i = e[i].next) {  
        int v = e[i].v;  
        if(v == fa && !flag) { flag = 1; continue; }  
        if(!vis[v]) {  
            Tarjan(v, u);  
            low[u] = min(low[u], low[v]);  
        } else if(col[v] == -1) low[u] = min(low[u], dfn[v]);  
        if(dfn[u] < low[v]) brige.pb(make_pair(u, v));  
    }  
    // 压栈取点构建连通分量
    if(low[u] == dfn[u]) {  
        while(stack[top-1] != u) col[stack[--top]] = bch, sum[bch] += a[stack[top]];  
        top --;  
        sum[bch] += a[stack[top]];  
        col[u] = bch ++;  
    }  
}  
// 建树缩点
void build() {  
    int sz = brige.size();  
    rep(i, sz) {  
        int u = brige[i].x, v = brige[i].y;  
        e[ne].v = col[v], e[ne].next = tree[col[u]];  
        tree[col[u]] = ne ++;  
        e[ne].v = col[u], e[ne].next = tree[col[v]];  
        tree[col[v]] = ne ++;  
    }  
}  
// 树形DP
int dfs(int u) {  
    int tmp = sum[u];  
    vis[u] = 1;  
    for(int i = tree[u]; i != -1; i = e[i].next) {  
        if(!vis[e[i].v]) tmp += dfs(e[i].v);  
    }  
    ans = min(ans, abs(all - 2 * tmp));  
    return tmp;  
}  
  
void init() {  
    mem(tree, -1);  
    mem(head, -1);  
    mem(col, -1);  
    mem(vis, 0);  
    mem(sum, 0);  
    brige.clear();  
    bch = top = all = ne = dfsNum = 0;  
}  
  
int main(){  
#ifdef LOCAL  
    IN // OUT  
#endif  
      
    while(sii(n, m) != EOF) {  
        init();  
        rep(i, n) si(a[i]), all += a[i];  
        int u, v;  
        rep(i, m) {  
            sii(u, v);  
            addEdge(u, v), addEdge(v, u);  
        }  
  
        Tarjan(0, 0);  
  
        if(bch != 1) {  
            build();  
            mem(vis, 0);  
            ans = inf;  
            dfs(0);  
            put(ans);  
        } else puts("impossible");  
    }  
      
    return 0;  
}  
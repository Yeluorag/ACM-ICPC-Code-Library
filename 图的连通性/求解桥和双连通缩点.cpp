struct edge {  
    int v, next;  
}e[5 * N];  
int ne, head[N];  
void addEdge(int u, int v) {  
    e[ne].v = v;  
    e[ne].next = head[u];  
    head[u] = ne ++;  
    e[ne].v = u;  
    e[ne].next = head[v];  
    head[v] = ne ++;  
}  
int dfsnum;  
int degree[N], dfn[N], low[N];  
bool exist[N][N];  
// Imp  
void init() {  
    ne = 0;  
    mem(degree, 0);  
    mem(head, -1);  
    mem(dfn, 0);  
    mem(exist, false);  
}  
  
void Tarjan(int u, int fa) {  
    dfn[u] = low[u] = ++ dfsnum;  
    for(int i = head[u]; i != -1; i = e[i].next) {  
        int v = e[i].v;  
        if(v == fa) continue;  
        if(!dfn[v]) {  
            Tarjan(v, u);  
            low[u] = (low[u], low[v]);  
            if(low[v] > dfn[u]) exist[u][v] = exist[v][u] = true;  // (u, v)是桥
        } else low[u] = (low[u], dfn[v]);  
    }  
}  
// 缩点
int cc[N], ccCnt;  
void dfs(int u, int fa) {  
    cc[u] = ccCnt;  
    for(int i = head[u]; i != -1; i = e[i].next) {  
        int v = e[i].v;  
        if(v != fa && !exist[u][v] && !cc[v])  
            dfs(v, u);  
    }  
}  
// 缩点后形成树，显然只需添加 (度数为1的点的个数 + 1) / 2 即可形成双连通分量
int work() {  
    mem(cc, 0); ccCnt = 1;  
    FOR(i, 1, n) {  
        if(!cc[i]) {  
            dfs(i, -1);  
            ccCnt ++;  
        }  
    }  
    FOR(i, 1, n) {  
        int u = i;  
        for(int j = head[i]; j != -1; j = e[j].next) {  
            int v = e[j].v;  
            if(cc[u] != cc[v]) degree[cc[u]] ++;  
        }  
    }  
    int ret = 0;  
    REP(i, 1, ccCnt) ret += degree[i] == 1;  
    return (ret + 1) / 2;  
}  
  
int main(){
    while(sii(n, m) != EOF) {  
        init();  
        int u, v;  
        rep(i, m) {  
            sii(u, v);  
            addEdge(u, v);  
        }  
        dfsnum = 0;  
        Tarjan(1, -1);  
        put(work());  
    }  
      
    return 0;  
}  
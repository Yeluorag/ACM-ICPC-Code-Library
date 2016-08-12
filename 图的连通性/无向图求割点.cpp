struct edge{  
    int v, next;  
}e[5 * N];  
int ne, head[N];  
void InitEdge() {  
    ne = 0;  
    mem(head, -1);  
}  
void addEdge(int u, int v) {  
    e[ne].v = v;  
    e[ne].next = head[u];  
    head[u] = ne ++;  
    e[ne].v = u;  
    e[ne].next = head[v];  
    head[v] = ne ++;  
}  
int low[N], dfn[N], cut[N], sub[N];  
int rootsub, dfsnum;  
// Imp  
void Tarjan(int u, int fa) {  
    low[u] = dfn[u] = ++ dfsnum;  
    for(int i = head[u]; i != -1; i = e[i].next) {  
        int v = e[i].v;  
        if(v == fa) continue;  
        if(!dfn[v]) {  
            Tarjan(v, u);  
            low[u] = min(low[u], low[v]);  
            if(low[v] >= dfn[u]) {  
                if(u != 1) sub[u] ++;  
                else rootsub ++;  
            }  
        } else low[u] = min(low[u], dfn[v]);  
    }  
}  
int main(){ 
    int u, v;  
    while(si(u), u) {  
        InitEdge();  
        mem(dfn, 0);  
        si(v), addEdge(u, v);  
        int node = max(u, v);  
        while(si(u), u) {  
            si(v), addEdge(u, v);  
            node = max(u, v);  
        }  
        rootsub = ne = 0;  
        mem(sub, 0);  
        Tarjan(1, 1);  
        if(cas ++) puts("");  
        printf("Network #%d\n", cas);  
        if(rootsub > 1) sub[1] = rootsub - 1;  
        bool ok = false;  
        FOR(i, 1, node) {  
            if(sub[i]) {  
                ok = true;  
                printf("  SPF node %d leaves %d subnets\n", i, sub[i] + 1);  
            }     
        }  
        if(!ok) puts("  No SPF nodes");  
    }  
      
    return 0;  
}  
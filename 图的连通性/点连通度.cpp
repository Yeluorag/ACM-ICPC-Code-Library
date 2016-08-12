// 题意：给一个无向图，求至少去掉多少个点可以将其变成不连通的。
/* 
其实可以把A、B看做源点和汇点。。那么点连通度就变为至少删多少个点才无法从源点到达汇点。
最小割。可是最小割割的是有容量的边，而这里却是点。稍微转换一下思路就好了，
把所有用到的点v变成两个点v'和v''，
并且这两点建边<v', v''>且容量为1，那么显然，删这条边就是删了点v。那么对其他边呢？
由于我们所要求的是要删顶点数，
所以不用关心边，那么对于原来边，由于每个点分化成了两个点，所以对原来的边e = <u, v>，
要新建成两条变 e' = <u'', v'> 和 e'' = <v'', u'>，
由于我们不关心这些边，所以直接容量设为无限大。这样这道题其实就变成了求这个网络图的最小割，
也就是求这个新建的网络图的最大流。
*/
int c[N][N];  
  
// EK  
int Maxflow(int s, int t) {  
    int fa[N], min_flow[N], cap[N][N];  
    int flow = 0;  
    mem(cap, 0);  
    while(true) {  
        queue<int> que;  
        mem(fa, -1);  
        fa[s] = -2;  
        min_flow[s] = inf;  
        que.push(s);  
        while(!que.empty()) {  
            int u = que.front(); que.pop();  
            rep(v, 2 * n) {  
                if(fa[v] == -1 && cap[u][v] < c[u][v]) {  
                    que.push(v);  
                    fa[v] = u;  
                    min_flow[v] = min(min_flow[u], c[u][v] - cap[u][v]);  
                }  
            }  
            if(fa[t] != -1) {  
                int k = t;  
                while(fa[k] >= 0) {  
                    cap[fa[k]][k] += min_flow[t];  
                    cap[k][fa[k]] -= min_flow[t];  
                    k = fa[k];  
                }  
                break;  
            }  
        }  
        if(fa[t] == -1) break;  
        flow += min_flow[t];  
    }  
    return flow;  
}  
int main(){  
      
    while(sii(n, m) != EOF) {  
        mem(c, 0);  
        int u, v;  
        rep(i, n) c[i][i+n] = c[i+n][i] = 1;  
        rep(i, m) {  
            scanf(" (%d,%d)", &u, &v);  
            c[u+n][v] = c[v+n][u] = inf;  
        }  
        int ans = inf;  
        REP(i, 1, n) ans = min(ans, Maxflow(n, i));  
        if(ans == inf) ans = n;  
        printf("%d\n", ans);  
    }  
      
    return 0;  
}  
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define min(a, b) (a<b)?a:b

const int vMax = 1005;
const int eMax = 40010;
const int inf = 0x7fffffff;

int dis[vMax], que[vMax], head[vMax], pre[vMax], qe[eMax], vis[vMax];
int ne, n, ans;

struct Edge
{
    int v, c, cost, next;
} e[eMax];

bool spfa()
{
    int i, f = 0, r = 1;
    
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    for(i = 0; i <= n; i++)
        dis[i] = inf;
    que[0] = 0;
    vis[0] = true;
    pre[0] = 0;
    dis[0] = 0;
    while(f != r)
    {
        int cur = que[f++];
        if(f == vMax) f = 0;
        vis[cur] = false;
        for(i = head[cur]; i != -1; i = e[i].next)
        {
            int u = e[i].v;
            if(e[i].c && dis[u] > dis[cur] + e[i].cost)
            {
                dis[u] = dis[cur] + e[i].cost;
                if(!vis[u])
                {
                    vis[u] = true;
                    que[r++] = u;
                    if(r == vMax) r = 0;
                }
                pre[u] = cur;
                qe[u] = i;
            }
        }
    }
    if(pre[n] == -1) return false;
    else return true;
}

void end()
{
    int i, tmp = inf;
    
    for(i = n; i != 0; i = pre[i])
        tmp = min(tmp, e[qe[i]].c);
    ans += dis[n] * tmp;
    for(i = n; i != 0; i = pre[i])
    {
        e[qe[i]].c -= tmp;
        e[qe[i]^1].c += tmp;
    }
}
void addEdge(int u, int v, int c, int cost)
{
    e[ne].v = v; e[ne].c = c; e[ne].cost = cost;
    e[ne].next = head[u]; head[u] = ne++;
    e[ne].v = u; e[ne].c = 0; e[ne].cost = -cost;
    e[ne].next = head[v]; head[v] = ne++;
}

int main()
{
    int N, M;
    int u, v, cost;
//    freopen("/Users/apple/input.txt","r",stdin);
    //freopen("a.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    memset(head, -1, sizeof(head));
    ne = ans = 0;
    n = N+1;
    while(M--)
    {
        scanf("%d%d%d", &u, &v, &cost);
        addEdge(u, v, 1, cost);
        addEdge(v, u, 1, cost);
    }
    addEdge(0, 1, 2, 0);
    addEdge(N, n, 2, 0);
    while(spfa()) {end();}
    printf("%d\n", ans);
    return 0;
}
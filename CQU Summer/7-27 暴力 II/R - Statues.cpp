#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int ans = 0, idx=0;
char maz[10][10];
int mtx[10][10][10];
struct node{
    int x, y, ret;
}m,s[105];

void init() {
   
    for(int j = 1; j < 8; j++){
        for(int i = 0; i < 8; i++)
            for(int k = 0; k < 8; k++)
                mtx[j][i][k] = mtx[j-1][i][k];
        for(int i = 0; i < idx; i++) {
            if(s[i].x >= 8) continue;
            int x = ++ s[i].x, y =s[i].y;
            mtx[j][x][y] ++;
            mtx[j][x-1][y] --;
        }
    }

}
void bfs() {
    queue<node> que;
    m.x = 7;
    m.y = 0;
    m.ret = 0;
    que.push(m);
    while(!que.empty()) {
        node now = que.front(); que.pop();
        if(now.ret >= 8) {
            ans = 1 ;
            return;
        }
        for(int i = -1; i <= 1; i++) {
            for(int j =-1; j <= 1; j++) {
                int nx = now.x + i, ny = now.y + j, nret = now.ret + 1;
                if(nx < 0 || ny < 0 || nx > 7 || ny > 7) continue;
                if(mtx[nret][nx][ny] == 0 && mtx[now.ret][nx][ny] == 0) {
                    node nxt;
                    nxt.x = nx;
                    nxt.y = ny;
                    nxt.ret = nret;
                    que.push(nxt);
                }
            }
        }
    }
    ans = 0;
}

int main(){
//        freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
    memset(mtx,0,sizeof(mtx));
    for(int i = 0; i < 8; i++)
        scanf("%s", maz[i]);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(maz[i][j] == 'S') {
                mtx[0][i][j] = 1;
                s[idx].x = i;
                s[idx++].y = j;
            }
        }
    }
    init();
    bfs();
    printf("%s\n",ans?"WIN":"LOSE");
    return 0;
}
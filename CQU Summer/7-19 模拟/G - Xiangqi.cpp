#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct point
{
    char name;
    int x,y;
}red[10]; 
 int dx[] = {-1, 0, 1, 0};
 int dy[] = {0, 1, 0, -1};


 int hx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
 int hy[] = {1, -1, 2, 2, 1, -1, -2, -2};
 int map[11][11]; 
 point bg, newbg;
 int n;


bool ismap(int x, int y)
{
    return y >= 4 && y <= 6 && x >= 1 && x <= 3;
}


int getsum_X(int y, int a, int b)
{
    int sum = 0;
    if (a < b)
    {
        for (int i = a + 1; i < b; i++)
        {
            if (map[i][y]) sum++;
        }
    }
    else
    {
        for (int i = b + 1; i < a; i++)
        {
            if (map[i][y]) sum++;
        }
    }
    return sum;
}


int getsum_Y(int x, int a, int b)
{
    int sum = 0;
    if (a < b)
    {
        for (int i = a + 1; i < b; i++)
        {
            if (map[x][i]) sum++;
        }
    }
    else
    {
        for (int i = b + 1; i < a; i++)
        {
            if (map[x][i]) sum++;
        }
    }
    return sum;
}




int check()
{
    for(int i=0;i<n;i++)
    {
     if(red[i].name=='G')
     {
        if (newbg.y == red[i].y)
         {
            if (getsum_X(newbg.y, newbg.x, red[i].x) == 0)
            return false;
         }
     }


     if(red[i].name=='C')
     {
        if(newbg.x == red[i].x && newbg.y == red[i].y) continue; //这就是吃掉了
        if(newbg.x == red[i].x)
        {
            if (getsum_Y(newbg.x, newbg.y, red[i].y) == 1) return false;
        }
        if (newbg.y == red[i].y)
        {
            if (getsum_X(newbg.y, newbg.x, red[i].x) == 1) return false;
        }
     }


    if(red[i].name=='R')
    {
        if (newbg.x == red[i].x && newbg.y == red[i].y) continue; 
        if (newbg.x == red[i].x)
        {
            if (getsum_Y(newbg.x, newbg.y, red[i].y) == 0) return false;
        }
        if (newbg.y == red[i].y)
        {
            if (getsum_X(newbg.y, newbg.x, red[i].x) == 0) return false;
        }
    }
        if(red[i].name=='H')
        {
            int newx, newy;
          for (int j = 0; j < 8; j++)
          {
            newx = red[i].x + dx[j / 2];
            newy = red[i].y + dy[j / 2];
            if (map[newx][newy]) continue; 
            newx = red[i].x + hx[j];
            newy = red[i].y + hy[j];
            if (newx == newbg.x && newy == newbg.y) return false;
          }
        }
    }
    return 1;
}


int main()
{
	freopen("/Users/apple/input.txt","r",stdin);
    char ch;
    int a,b;
    while (cin >> n >> bg.x >> bg.y, n)
    {
        //gc = rc = hc = cc = 0;
        memset(map, 0, sizeof(map));
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> ch >> a >> b;
            map[a][b] = 1;
            red[i].name=ch;
            red[i].x=a;
            red[i].y=b;
        }


        for (int i = 0; i < 4; i++)
        {
            newbg.x = bg.x + dx[i];
            newbg.y = bg.y + dy[i];
            if (!ismap(newbg.x, newbg.y)) continue;
            if (check())
            {
                flag = false;
                break;
            }
        }
        if(flag)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    return 0;
}
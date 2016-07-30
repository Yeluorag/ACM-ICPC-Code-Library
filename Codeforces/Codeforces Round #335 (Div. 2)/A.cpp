#include <iostream>
using namespace std;
#define LOCAL
int main()
{
    #ifdef LOCAL
        freopen("/Users/apple/input.txt","r",stdin);
        //    freopen("/Users/apple/out.txt","w",stdout);
    #endif
    

    int a, b, c, x, y, z;
    cin >> a>>b>>c>>x>>y>>z;

    int poz=max(a-x, 0)/2+max(b-y, 0)/2+max(c-z, 0)/2;
    int neg=max(x-a, 0)+max(y-b, 0)+max(z-c, 0);

    if (poz>=neg) {
        cout << "YES"<<endl;
    } else {
        cout << "NO"<<endl;
    }

    return 0;
}
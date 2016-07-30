LL a[N], m[N];  
LL gcd(LL a,LL b) {  
    return b? gcd(b, a % b) : a;  
}  
  
void extend_Euclid(LL a, LL b, LL &x, LL &y) {  
    if(b == 0) {  
        x = 1;  
        y = 0;  
        return;  
    }  
    extend_Euclid(b, a % b, x, y);  
    LL tmp = x;  
    x = y;  
    y = tmp - (a / b) * y;  
}  
// 求逆元
LL Inv(LL a, LL b)   {  
    LL d = gcd(a, b);  
    if(d != 1) return -1;  
    LL x, y;  
    extend_Euclid(a, b, x, y);  
    return (x % b + b) % b;  
}  
  
bool merge(LL a1, LL m1, LL a2, LL m2, LL &a3, LL &m3) {  
    LL d = gcd(m1, m2);  
    LL c = a2 - a1;  
    if(c % d) return false;  
    c = (c % m2 + m2) % m2;  
    m1 /= d;  
    m2 /= d;  
    c /= d;  
    c *= Inv(m1, m2);  
    c %= m2;  
    c *= m1 * d;  
    c += a1;  
    m3 = m1 * m2 * d;  
    a3 = (c % m3 + m3) % m3;  
    return true;  
}  
  
LL CRT(LL a[], LL m[], int n) {  
    LL a1 = a[1];  
    LL m1 = m[1];  
    for(int i = 2; i <= n; i ++) {  
        LL a2 = a[i];  
        LL m2 = m[i];  
        LL m3, a3;  
        if(!merge(a1, m1, a2, m2, a3, m3))  
            return -1;  
        a1 = a3;  
        m1 = m3;  
    }  
    return (a1 % m1 + m1) % m1;  
}  
void exgcd(int a, int b, int &d, int &x, int &y) {
	if(!b) { d = a; x = 1; y = 0; }
	else { exgcd(b, a%b, d, y, x); y -= x * (a / b); }
}
int exgcd(int a, int b, int& x, int& y) {  
    if(b == 0) {  
        x = 1, y = 0;  
        return a;  
    }  
    int d = exgcd(b, a % b, x, y);  
    int tmp = x;  
    x = y;  
    y = tmp - a / b * y;  
    return d;  
}

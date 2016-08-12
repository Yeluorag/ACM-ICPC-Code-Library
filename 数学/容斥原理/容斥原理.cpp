vector<int> pr[N];
// pr[k]表示k的所有素因子
// index表示此刻算到哪个质因数，t表示在1~b中计算被质因数整除的个数，指第二个区间的哪一个数。   
// 求的是 1 ~ t 中与n互素的个数
LL Inclusion_exclusion(int idx, int t, int n) {
    LL ret = 0, tmp;
    int sz = pr[n].size();
    for(int i = idx; i < sz; i ++) {
        tmp = t / pr[n][i];
        ret += tmp - Inclusion_exclusion(i + 1, tmp, n);
    }
    return ret;
}

// cnt[i]表示因子含有i的数的个数。
void Inclusion_exclusion() {
    int nop = 0;
    int v = tmp.size();
    int nn = 1 << v;
    for(int j = 1; j < nn; j++) {
        int flag = 0;
        int mul = 1;
        for(int k = 0; k < v; k++) {
            if((j >> k) & 1) {
                flag++;
                mul *= tmp[k];
            }
        }
        if(flag & 1) nop += cnt[mul]; else nop -= cnt[mul];
    }
}
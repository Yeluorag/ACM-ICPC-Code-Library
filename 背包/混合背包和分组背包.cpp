/*
n个工作组，每组m份工作，每组有一个状态s，s为0时至少做一件，为1时最多做一件，为2时任意取。
s = 0时，至少选一个，对第i组j时间第k份工作，先与当前组比较，
因为每个dp[i][j]未更新时初始化为-1，所以一定会选到，这
就满足了至少选一个的条件。然后再与i-1组比较，更新相对前i组的最优值。
s = 1时，不与当前组比较更新，只与i-1组比较。这是显然的，
对第k个，只能与i-1组的比较选或不选，不会与第k个之前的有关系，所以至多选了一个。
s = 1时，01背包。
*/
int dp[N][N], w[N], v[N];  
// Imp  
void tpe0(int i) {  
    rep(k, m) {  
        for(int j = t; j >= w[k]; j --) {  
            if(dp[i][j-w[k]] != -1) Max(dp[i][j], dp[i][j-w[k]] + v[k]);    //至少选1个  
            if(dp[i-1][j-w[k]] != -1) Max(dp[i][j], dp[i-1][j-w[k]] + v[k]);//带上之前的找到最优解  
        }  
    }  
}  
void tpe1(int i) {  
    FOR(j, 0, t) dp[i][j] = dp[i-1][j];  
    rep(k, m) {  
        for(int j = t; j >= w[k]; j --) {  
            if(dp[i-1][j-w[k]] != -1)  
                Max(dp[i][j], dp[i-1][j-w[k]] + v[k]);  //不可包含当前组的前置状态  
        }  
    }  
}  
void tpe2(int i) {  
    FOR(j, 0, t) dp[i][j] = dp[i-1][j];  
    rep(k, m) {  
        for(int j = t; j >= w[k]; j --) {  
            if(dp[i][j-w[k]] != -1)  
                Max(dp[i][j], dp[i][j - w[k]] + v[k]);  //01背包  
        }  
    }  
}  
  
int main(){  
    while(sii(n, t) != EOF) {  
        mem(dp, -1);  
        mem(dp[0], 0);  
        FOR(i, 1, n) {  
            sii(m, s);  
            rep(j, m) sii(w[i], v[i]);  
            switch(s) {  
                case 0: tpe0(i); break;  
                case 1: tpe1(i); break;  
                case 2: tpe2(i); break;  
                default: break;  
            }  
        }  
        printf("%d\n", dp[n][t]);  
    }  
      
      
    return 0;  
}  
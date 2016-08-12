#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char a[1001],b[1001],t[1001];
    scanf("%s%s",a,b);
    strcpy(t,a);
    int m,n,f1=0;
    m=strlen(a);
    n=strlen(b);
    int m1=m,n1=n,k=0;
    for(int i=0;i<n;i++){
        for(int j=k;j<m;j++){
            if(b[i]==a[j]){
                n1--;
                k=j+1;
                break;
            }
        }
    }
    if(n1==0)f1=1;
    m1=m,n1=n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            if(b[i]==a[j]) {m1--;n1--;a[j]=='\0';break;}
    }
    if(m1==0&&n1==0) printf("array\n");
    else if(m1>0&&n1==0&&f1==1)printf("automaton\n");
    else if(m1>0&&n1==0&&f1==0)printf("both\n");
    else printf("need tree\n");
    return 0;
}

/*
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;


const int N = 105;
char s[N], t[N];

const int L = 26;
int cnt[L];

int main() {
	scanf("%s%s", s, t);
	int l0 = strlen(s), l1 = strlen(t);
	for (int i = 0; i < l0; ++i) {
		++cnt[s[i] - 'a'];
	}
	for (int i = 0; i < l1; ++i) {
		--cnt[t[i] - 'a'];
	}
	bool automation = true, array = true, both = true;
	for (int i = 0; i < L; ++i) {
		array = array && cnt[i] == 0;
		both = both && cnt[i] >= 0;
	}
	int j = 0;
	for (int i = 0; i < l0; ++i) {
		if (j < l1 && t[j] == s[i]) {
			++j;
		}
	}
	automation = j == l1;
	string ans;
	if (automation) {
		ans = "automaton";
	} else if (array) {
		ans = "array";
	} else if (both) {
		ans = "both";
	} else {
		ans = "need tree";
	}
	printf("%s\n", ans.c_str());
	return 0;
}
*/

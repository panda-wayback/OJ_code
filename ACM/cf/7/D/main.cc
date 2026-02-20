#include <bits/stdc++.h>
using namespace std;

long long sl, f, b, MOD = 998244353;
char s[5000005];
long long base = 1;
int dp[5000005], ans = 0;

inline void get_hash(int x) {
	f = (f * 32767ll + (long long)s[x] + MOD) % MOD;
	b = (b + (long long)(s[x]) * base + MOD) % MOD;
	base = base * 32767ll % MOD;
}

int main(){
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);

	scanf("%s",s);
	sl = strlen(s);
	for (register int i = 0; i < sl; i++) {
		get_hash(i);
		if(f == b) {//f是正着的哈希，b是倒着的
			dp[i] = dp[(i - 1 >> 1)] + 1, ans += dp[i];
			cout<<"asd "<<i<<endl;
		}
	}
	printf("%d", ans);
	return 0;
}
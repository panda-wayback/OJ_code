#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 55;
const int MAXS = MAXN;              // 只记「总超额分」j ∈ [0, n-1]，总得分 = L + j

// ========== 题意与等价条件 ==========
// 统计 (x_1,...,x_N) 的个数：每个 x_i 为长 N²、值域 [1,N] 的序列，
// 满足「对任意序列 y，都存在某个 i 使得 d(x_i,y) >= N²-N」。
//
// 题解等价：BAD = 存在 y 使所有 i 都满足 d(x_i,y) <= N²-N-1。
// 对每一列 j，令 d_j = 该列 N 个数中出现次数最多的值的出现次数（众数频数）。
// BAD 当且仅当 sum_j d_j >= N²+N，故答案 = 满足 sum_j d_j < N²+N 的 (x_1,...,x_N) 个数。

int n;                          // 输入：1 <= n <= 50
int fact[MAXN], invf[MAXN];     // 阶乘与逆元，用于组合数
int F[MAXN];                    // F[t] = 单列中每种数出现次数都 <= t 的方案数
int f[MAXN];                    // f[t] = 单列众数频数恰好为 t 的方案数
// dp[i][j] 语义：前 i 列总得分为 j 的方案数；用两行滚动省内存
int dp[2][MAXS];

// 模意义下加法、乘法、快速幂
int add(int a, int b) { return (a + b) % MOD; }
int mul(int a, int b) { return (int)((long long)a * b % MOD); }
int pow_mod(int a, int b) {
    int r = 1;
    for (; b; b >>= 1, a = mul(a, a))
        if (b & 1) r = mul(r, a);
    return r;
}

// 预处理 0..n 的阶乘与阶乘逆元
void init_fact(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mul(fact[i - 1], i);
    invf[n] = pow_mod(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) invf[i] = mul(invf[i + 1], i + 1);
}

// 组合数 C(n,k) mod MOD
int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return mul(fact[n], mul(invf[k], invf[n - k]));
}

// 计算 F(t)：单列 N 个数、值域 [1,N]，每种值出现次数都 <= t 的方案数。
// 用于后面得到 f(t) = F(t) - F(t-1)，即众数频数恰好为 t 的方案数。
// 内部 DP：ways[pos][val] = 用前 val 种数填了 pos 个位置、每种最多 t 次的方案数；
// 转移时从剩余 n-pos 个位置中选 use 个填成第 val+1 种数，use in [0, min(t, n-pos)]。
int calc_F(int t) {
    static int ways[MAXN][MAXN];
    memset(ways, 0, sizeof ways);
    ways[0][0] = 1;
    for (int val = 0; val < n; val++)
        for (int pos = 0; pos <= n; pos++) {
            if (!ways[pos][val]) continue;
            for (int use = 0; use <= min(t, n - pos); use++)
                ways[pos + use][val + 1] = add(ways[pos + use][val + 1],
                    mul(C(n - pos, use), ways[pos][val]));
        }
    return ways[n][n];
}

void run() {
    cin >> n;
    init_fact(n);

    // 预处理 f(t)：单列众数频数恰好为 t 的方案数
    F[0] = 0;
    for (int t = 1; t <= n; t++) F[t] = calc_F(t);
    for (int t = 1; t <= n; t++) f[t] = (F[t] - F[t - 1] + MOD) % MOD;

    int L = n * n;  // 总列数；总得分 = L + 总超额分，要总得分 < L+n 即总超额分 < n

    // 主 DP：只记「总超额分」j（每列贡献 t-1），j ∈ [0, n-1]，复杂度 O(L*n²)=O(n^4)
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for (int i = 0; i < L; i++) {
        int cur = i & 1, nxt = (i + 1) & 1;
        memset(dp[nxt], 0, sizeof dp[nxt]);
        for (int j = 0; j < n; j++) {
            if (dp[cur][j] == 0) continue;
            for (int t = 1; t <= n; t++) {
                int excess = t - 1;  // 该列超额分
                if (j + excess < n)
                    dp[nxt][j + excess] = add(dp[nxt][j + excess], mul(dp[cur][j], f[t]));
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < n; j++) ans = add(ans, dp[L & 1][j]);
    cout << ans << "\n";
}

int main() {
#if defined(__APPLE__) || defined(__WIN32__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

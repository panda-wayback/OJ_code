#include <bits/stdc++.h>
using namespace std;
void run();

int main() {
#if defined(__APPLE__) || defined(__WIN32__ )
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}
long long arr[1000005], tag[1000005], ans_arr[1000005];
void run() {
    long long n, m;
    cin >> n >> m;

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (long long i = 0; i < m; i++) {
        long long x, y;
        cin >> x >> y;
        tag[x - 1] += 1;
        tag[y] -= 1;
    }

    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        sum += tag[i];
        ans_arr[i] += sum;
    }

    sort(ans_arr, ans_arr + n);
    long long res = 0;
    for (long long i = n - 1; i >= 0; --i) {
        res += ans_arr[i] * arr[i];
    }
    cout << res << endl;
}
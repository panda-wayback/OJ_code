#include <bits/stdc++.h>
using namespace std;
void run();
void run2(int n, int m);
int main() {
#if defined(__APPLE__) || defined(__WIN32__ )
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

void run() {
    int n, m;
    while (cin >> n && n != 0) {
        cin >> m;

        run2(n, m);
    }
}
int fn[1005];

int findx(int n) {
    // cout << "tag  " << n << ' ' << fn[n] << endl;
    if (fn[n] != n) {
        fn[n] = findx(fn[n]);
    }

    return fn[n];
}
void run2(int n, int m) {
    int x, y;
    for (int i = 0; i <= n; i++) {
        fn[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        int fx = findx(x);
        int fy = findx(y);
        fn[fy] = fn[fx];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // cout << fn[i] << ' ';
        if (fn[i] == i) {
            ans += 1;
        }
    }
    // cout << endl;
    cout << ans - 1 << endl;
}
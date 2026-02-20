#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void run();

int main() {
#if defined(__APPLE__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

void run() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0, r = n - 1;
    pair<int, int> x, y;
    while (l <= r) {
        if (x.first <= y.first) {
            x.second += 1;
            x.first += arr[l++];
        } else {
            y.second += 1;
            y.first += arr[r--];
        }
    };
    cout << x.second << ' ' << y.second << endl;
}

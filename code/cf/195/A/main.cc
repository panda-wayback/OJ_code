#include <bits/stdc++.h>
using namespace std;
void init(int &index1, int &index2, int &m, int &tag) {
    if (index1 == m + 1 && index2 == 0) {
        index1 = (m + 2) / 2;
        index2 = index1 - 1;
        tag = true;
        if (m % 2 == 0)
            tag = false;
    }
}

void run() {
    int n, m;
    cin >> n >> m;
    int index1 = m + 1, index2 = 0, tag;
    while (--n >= 0) {
        init(index1, index2, m, tag);
        if (tag) {
            cout << index1++ << endl;
        } else {
            cout << index2-- << endl;
        }
        tag = !tag;
    }
}

int main() {
#if defined(__APPLE__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}
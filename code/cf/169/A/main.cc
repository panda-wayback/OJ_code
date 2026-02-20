#include <bits/stdc++.h>
using namespace std;
void run();

int main() {
#if defined(__APPLE__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

int arr[27];
void run() {
    string str;
    cin >> str;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < str.size(); ++i) {
        int index = str[i] - 'a';
        arr[index] += 1;
    }
    int m = 0;
    for (int i = 0; i < 26; ++i) {
        if (arr[i] % 2 == 1) {
            ++m;
        }
    }
    if (m == 0 || m % 2 == 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}
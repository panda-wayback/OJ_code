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

void run() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int j = 0, ans = -1;
    multiset<int> s; //尺取法删除头 增加尾部，并且取最大最小的差进行对比。
    vector<pair<int, int> > vp;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);

        while (*s.rbegin() - *s.begin() > k) {
            s.erase(s.find(arr[j++])); 
        }

        if (i - j + 1 > ans) {
            ans = i - j + 1;
            vp.clear();  //如果遇到更大的 就清空之前记录的
        }
        if (i - j + 1 == ans) {
            vp.push_back(make_pair(j + 1, i + 1));
        }
    }

    cout << ans << ' ' << vp.size() << endl;
    for (int i = 0; i < vp.size(); i++) {
        cout << vp[i].first << ' ' << vp[i].second << endl;
    }
}
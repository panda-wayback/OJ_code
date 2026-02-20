#include <bits/stdc++.h>
using namespace std;

void clean_statck(stack<int> &arr) {
    while (!arr.empty()) {
        arr.pop();
    }
}

void show(vector<int> &arr) {
    cout << "show vector" << endl;
    for (auto a : arr) {
        cout << setw(11) << a << ' ';
    }
    cout << endl;
}

void run() {
    int n;
    cin >> n;
    vector<int> arr(n + 2), left_tag(n + 2), right_tag(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        left_tag[i] = i - 1;
        right_tag[i] = i + 1;
    }
    arr[0] = INT_MAX;
    arr[n + 1] = INT_MAX;
    left_tag[0] = right_tag[0] = 0;
    left_tag[n + 1] = right_tag[n + 1] = n + 1;

    for (int i = 1; i <= n; i++) {
        while (arr[left_tag[i]] < arr[i]) {
            left_tag[i] = left_tag[left_tag[i]];
        }
    }

    for (int i = n; i >= 1; i--) {
        while (arr[right_tag[i]] < arr[i]) {
            right_tag[i] = right_tag[right_tag[i]];
        }
    }

    show(left_tag);
    show(right_tag);
    show(arr);

    int ans = 0;

    for (int i = n; i >= 0; i--) {
        int tem = left_tag[i];
        while (tem != 0) {
            tem = left_tag[tem];
            ++ans;
        }
    }
    cout<<ans<<endl;

    for (int i = 1; i <= n; i++) {
        int tem = right_tag[i];
        while (tem != n + 1) {
            if(arr[i] != arr[tem] && tem != n+1){
                cout<<"asd  "<<arr[i]<<' '<<arr[tem]<<endl;
                ++ans;
            }
            tem = right_tag[tem];

        }
    }
    cout << ans << endl;
}

int main() {
#if defined(__APPLE__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}
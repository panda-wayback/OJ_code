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

int n, a, b, min_times = 1e3;
vector<int> result(10000);
void dfs(int index, int depth, vector<int> &arr, vector<int> &tag) {
    if (index == n) {
        if (arr[index - 1] >= 0 || arr[index] >= 0)
            return;

        if (depth < min_times) {
            min_times = depth;
            for (int i = 0; i < depth; i++) {
                result[i] = tag[i];
            }
        }
        return;
    }

    int his_arr_index = arr[index];
    int his_arr_index_sec = arr[index - 1];
    int his_arr_index_fir = arr[index + 1];
    int his_depth = depth;
    if (index == n - 1) {
        while (arr[index] >= 0 || arr[index - 1] >= 0 || arr[index + 1] >= 0) {
            arr[index] -= a;
            arr[index - 1] -= b;
            arr[index + 1] -= b;
            tag[depth++] = index;
        }

        dfs(index + 1, depth, arr, tag);

        arr[index] = his_arr_index;
        arr[index - 1] = his_arr_index_sec;
        arr[index + 1] = his_arr_index_fir;
        depth = his_depth;
        return;
    }

    while ( arr[index - 1] >= 0) {
        arr[index] -= a;
        arr[index - 1] -= b;
        arr[index + 1] -= b;
        tag[depth++] = index;
    } dfs(index + 1, depth, arr, tag);
    while (arr[index] >= 0 ) {
        arr[index] -= a;
        arr[index - 1] -= b;
        arr[index + 1] -= b;
        tag[depth++] = index;
        dfs(index + 1, depth, arr, tag);
    }

    arr[index] = his_arr_index;
    arr[index - 1] = his_arr_index_sec;
    arr[index + 1] = his_arr_index_fir;
    depth = his_depth;
}

void run() {

    cin >> n >> a >> b;
    vector<int> arr(n + 1);
    vector<int> tag(n * 1000);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dfs(2, 0, arr, tag);
    cout << min_times << endl;
    for (int i = 0; i < min_times; i++) {
        cout << result[i] << ' ';
    }
    cout << endl;
}
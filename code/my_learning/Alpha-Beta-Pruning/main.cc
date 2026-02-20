#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    vector<int> child;
    bool is_max;
    bool is_value;
};
Node tree[1000];

void input_tree(int n) {

    for (int i = 0; i < n; i++) {
        int node, child_num;
        cin >> node >> child_num;
        for (int j = 0; j < child_num; j++) {
            int child;
            cin >> child;
            tree[node].child.push_back(child);
        }
    }
}

void input_value(int m) {
    for (int i = 0; i < m; ++i) {
        int index, value;
        cin >> index >> value;
        tree[index].value = value;
        tree[index].is_value = true;
    }
}

int alpha_beta(int node, bool is_max) {

    if (tree[node].is_value) {
        return tree[node].value;
    }

    int result = is_max ? -100000 : 100000;
    tree[node].is_max = is_max;

    for (int i = 0; i < tree[node].child.size(); ++i) {
        int child = tree[node].child[i];
        int child_result = alpha_beta(child, !is_max);
        if (is_max) {
            result = max(result, child_result);
        } else {
            result = min(result, child_result);
        }
    }
    tree[node].value = result;
    cout << "node " << node << ' ' << tree[node].value << ' ' << is_max << endl;
    return result;
}

int alpha_beta_pruning(int node, int alpha, int beta, bool is_max) {

    if (tree[node].is_value) {
        return tree[node].value;
    }

    tree[node].is_max = is_max;

    for (int i = 0; i < tree[node].child.size(); ++i) {
        int child = tree[node].child[i];
        int child_result = alpha_beta(child, !is_max);
        if (is_max) {
            alpha = max(alpha, child_result);
            tree[node].value = alpha;
            if (alpha >= beta)
                break;
        } else {
            beta = min(beta, child_result);
            tree[node].value = beta;
            if (alpha >= beta)
                break;
        }
    }
    return tree[node].value;
}

void run() {

    int n;
    cin >> n;
    input_tree(n);

    int m;
    cin >> m;
    input_value(m);

    for (int i = 0; i < 27; ++i) {
        cout << i << ' ' << tree[i].value << endl;
    }

    // int res = alpha_beta(1 , true);
    int res = alpha_beta_pruning(1, -100000, 100000, true);
    cout << "res : " << res << endl;
}

int main() {
#if defined(__APPLE__) || defined(__WIN32__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

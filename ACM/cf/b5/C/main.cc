/**
 * 这么看 有一种输入 (((()) , 这种情况只有后四个是合法的
 * 所以需要换一种统计合法长度的放法
 *
 *
 *
 *
 *
 * */

#include <bits/stdc++.h>
using namespace std;
void show(vector<int> &arr) {
    for (auto a : arr) {
        cout << a;
    }
    cout << endl;
}

void run() {
    string str;
    cin >> str;
    stack<int> tem_stack;
    vector<int> tag_str(str.size());
    //这里，将所有的合法匹配的都标记为1 ， 那么最后只需要数最长的1 的个数就够了
    for (int i = 0; i < str.size(); i++) { 
        if (str[i] == '(') {
            tem_stack.push(i);
        } else if (str[i] == ')') {
            if (tem_stack.size()) {
                tag_str[tem_stack.top()] = 1;
                tag_str[i] = 1;
                tem_stack.pop();
            }
        }
    }

    int maxs = 0, times = 1, tem_len = 0;
    for (int i = 0; i < tag_str.size(); i++) {
        if (tag_str[i] == 1) {
            ++tem_len;
        }
        if (tag_str[i] == 0 || i == tag_str.size() - 1) {
            if (tem_len == maxs && tem_len) {
                ++times;
            } else if (tem_len > maxs) {
                maxs = tem_len;
                times = 1;
            }
            tem_len = 0;
        }
    }

    // show(tag_str);

    cout << maxs << ' ' << times << endl;
}

int main() {
#if defined(__APPLE__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}
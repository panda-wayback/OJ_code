#include <bits/stdc++.h>
using namespace std;

// 题意：给定主人名字 S（首字母大写，其余小写），女仆名为 "Of" + 首字母小写后的 S。
void run() {
    string s;
    cin >> s;
    // 将首字母转为小写
    s[0] = tolower(s[0]);
    // 输出 "Of" + 处理后的名字
    cout << "Of" << s << "\n";
}

int main() {
#if defined(__APPLE__) || defined(__WIN32__)
    // 本地/Windows：从 slyar.in 读入，输出到 slyar.out
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

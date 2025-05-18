#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// 在这里定义你的 Solution 类
class Solution {
public:
    // 在这里实现你的解法
    void solve() {
        // TODO: 实现你的解法
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // TODO: 实现你的解法
        return {};
    }
};

// 用于本地调试的函数
void run() {
    Solution solution;
    
    // 读取输入
    vector<string> strs;
    string str;
    while (cin >> str) {
        strs.push_back(str);
    }
    
    // 调用解法
    auto result = solution.groupAnagrams(strs);
    
    // 输出结果
    for (const auto& group : result) {
        for (const auto& s : group) {
            cout << s << " ";
        }
        cout << endl;
    }
}

int main() {
    // 本地调试时自动重定向输入输出
#if defined(__APPLE__) || defined(__WIN32__)
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    
    // 设置输出精度
    cout << fixed << setprecision(6);
    
    // 运行测试
    run();
    
    return 0;
}

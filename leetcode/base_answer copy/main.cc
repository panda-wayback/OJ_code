#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

// 用于本地调试的函数
void run() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        int num = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            int x = s[i] - '0';
            if(x % 3 == 0) {
                res += 1;
            }
            num += x;
        }
        
        for(int i = 0; i < s.size(); i++) {
            if((num - (s[i] - '0')) % 3 == 0) {
                num = num - (s[i] - '0');
                res += 1;
                break;
            }
        }
        if(num % 3 == 0) {
            cout << res - 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
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

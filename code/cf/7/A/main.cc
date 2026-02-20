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
    char s[10]; //模拟棋盘
    int a = 0, b = 10;
    for (int i = 0; i < 8; i++) {
        scanf("%s", s); //输入棋盘的每一行
        int count = 0;  //计数器
        for (int j = 0; j < 8; j++)
            if (s[j] == 'B')
                count++;
        if (count == 8)
            a++; //如果全为B，就涂
        b = std::min(b, count);
    }
    int ans = a + b;
    if (a == 8)
        ans = 8;       //如果全为B，则只需涂8次
    printf("%d", ans); //输出结果
}
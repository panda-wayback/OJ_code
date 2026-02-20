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

long long a, b, c, x, y, d; //这道题要开long long！！！

int exgcd(int a, int b) //扩展欧几里得
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }                          //临界条件
    int tmp = exgcd(b, a % b); //逆推回去求解
    int t = x;
    x = y;
    y = t - a / b * y;
    return tmp;
}

void run() {
    scanf("%lld%lld%lld", &a, &b, &c);
    c = -c;
    int d = exgcd(a, b);
    if (c % d != 0) {
        printf("-1\n");
        return;
    } //如果无解
    x = c / d * x;
    y = c / d * y; //这里是求出k=0时的通解
    printf("%lld %lld\n", x, y);
    return; //功德圆满
}

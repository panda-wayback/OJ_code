/**
 * 
首先，问号的状态会影响能否匹配，那么我们不妨就先让所有问号都为右括号，什么时候右括号太多了就把前面的问号改成左括号即可。

那么前面有多个问号的时候我们应该选择哪个？显然我们应该运用贪心思想，哪个问号改变后为我们减少的花费多我们就选哪个，这就需要我们维护一个优先队列，排序的依据是-b+a−b+a的大小（bb是该问号改为右括号的价值，aa是该问号改为左括号的价值）。我们每遇到一个问号就把它推进队列里，以备之后选用。每选用一个括号就把它改为左括号，同时修改我们的answeranswer和计数器。

当然，在这个过程中我们还需要判断能否匹配。不匹配的情况总共两种：

1.发现右括号比左括号还多后前面却没有问号用来抵消

2.到最后发现左括号比右括号和问号的和还多

这时输出-1−1即可。
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y, index;
    Node() {}
    Node(int x, int y, int index) : x(x), y(y), index(index) {} //赋值
    bool operator<(const Node &a) const                         //从大到小
    {
        return y - x < a.y - a.x;
    }
    bool operator>(const Node &a) const //从小到大
    {
        return x > a.x;
    }
    // priority_queue<Node> p1;//默认从大到小
    // 等价于priority_queue<Node,vector<Node>,less<Node> > p1;
};
void run() {
    string braces_str;
    cin >> braces_str;

    long long right_cost = 0;
    priority_queue<Node> p1;
    int braces_count_left = 0,
        braces_count_right = 0; // Calculate the sum of them
    for (int i = 0; i < braces_str.size(); i++) {
        if (braces_str[i] == '?') {
            int x, y;
            cin >> x >> y;
            p1.push(Node(x, y, i));
            right_cost += y;
            braces_count_right += 1;
            braces_str[i] = ')';
        } else if (braces_str[i] == ')') {
            braces_count_right += 1;
        } else {
            braces_count_left += 1;
        }

        if (braces_count_left - braces_count_right == -1) {
            if (!p1.empty()) {

                braces_count_left += 1;
                braces_count_right -= 1;
                right_cost -= p1.top().y - p1.top().x;
                braces_str[p1.top().index] = '(';
                p1.pop();
            }
            else{
                cout << "-1" << endl;
                return;
            }
        }
    }
    if (braces_count_left != braces_count_right  ) {
        cout << "-1" << endl;
        return;
    }
    cout << right_cost << endl;
    cout << braces_str << endl;
}

int main() {
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
    run();
}
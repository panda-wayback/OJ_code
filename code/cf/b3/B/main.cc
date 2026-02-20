/** 
 * 刷完人都傻了- - 
 * 最后贪心是这么贪心的 
 * 1. 优先放最大的 1 的价值
 * 2. 之后看两个1 的价值是不是比2 大
 * 3. 最后放2 的价值
 * 
 * 最后如果空间还有1   那么有两种放法
 * 1. 放一个1
 * 2. 取出一个1 放一个2
 * 
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node(int _x, int _y, int _index) : x(_x), y(_y), index(_index){};
    int x, y, index;
};

bool cmp(Node &a, Node &b) { return a.y < b.y; }

void input(int n, vector<Node> &arr1, vector<Node> &arr2) {
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            arr1.push_back(Node(x, y, i + 1));
        } else if (x == 2) {
            arr2.push_back(Node(x, y, i + 1));
        } else {
            cout << "ERROR ! " << endl;
        }
    }
    sort(arr1.begin(), arr1.end(), cmp);
    sort(arr2.begin(), arr2.end(), cmp);
}

int getLastSum(vector<Node> &arr) {

    return arr.back().y + arr[arr.size() - 2].y;
}

void runTag(int &ans, vector<Node> &arr1, vector<Node> &resultTag) {
    ans += arr1.back().y;
    resultTag.push_back(arr1.back());
    arr1.pop_back();
}

void run() {
    int n, v;
    cin >> n >> v;

    vector<Node> arr1, arr2;
    input(n, arr1, arr2);

    int ans = 0;

    vector<Node> resultTag1, resultTag2;
    while (v > 0) {
        if (!arr1.empty() && ( arr2.empty() || arr1.back().y > arr2.back().y )  ){
            v -= 1;
            runTag(ans, arr1, resultTag1);
        } else if (v>=2 && arr1.size() >= 2 && arr2.size() && getLastSum(arr1) > arr2.back().y) {
            v -= 2;
            runTag(ans, arr1, resultTag1);
            runTag(ans, arr1, resultTag1);
        } else if(v>=2 && arr2.size() ) {
            runTag(ans, arr2, resultTag2);
            v -= 2;
        }
        else{
            break;
        }
    }

    //cout<<ans<<' '<<v<<endl;


         
    if(v == 1  ){
        if(arr1.size() ){
            runTag(ans, arr1, resultTag1);
            v -= 1 ;
        }
        if(v == 1 && arr2.size() && resultTag1.size()){
            int tem = ans - resultTag1.back().y ;
            if(tem + arr2.back().y > ans){
                ans = tem;
                runTag(ans, arr2, resultTag2);
                resultTag1.pop_back();
            }
        }
        else if(arr2.size() && resultTag1.size() >= 2){
            int tem = ans - resultTag1.back().y - resultTag1[resultTag1.size() - 2].y;
            if(tem + arr2.back().y > ans){
                ans = tem;
                runTag(ans, arr2, resultTag2);
                resultTag1.pop_back();
                resultTag1.pop_back();
            }
        }

    }
    //cout<<ans<<' '<<v<<endl;
    cout<<ans<<endl;
    if(ans == 36651){
        cout<<ans<<' '<<v<<endl;
    }
    for (auto tem : resultTag1) {
        cout << tem.index << ' ';
    }
    for (auto tem : resultTag2) {
        cout << tem.index << ' ';
    }
    cout << endl;
}

int main() {
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
    run();
}
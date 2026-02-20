#include <bits/stdc++.h>
using namespace std;

struct node{
    int x;
    int y;
    int z;
    node(int x, int y, int z):x(x),y(y),z(z){}
    node(){}
    //根据z排序
    bool operator < (const node &a) const{
        return z < a.z;
    }
};

// 计算两个node的欧几里得距离
double getDistance(const node &a,const node &b){
    double distance = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z) );
    return distance;
}

void run(){
// 5
// 2 2 2
// 1 1 1
// 4 4 4
// 3 3 3
// 5 5 5
// cin this data
    int n;
    cin >> n;
    vector<node> a(n);
    for(int i = 0 ; i < n; ++i){
        int x,y,z;
        cin >> x >> y >> z;
        a[i] = node(x,y,z);
    }
    sort(a.begin(),a.end());
    node start = a[0];
    double ans = 0;
    for(int i =0 ; i < n; ++i){
        if(a[i].z > start.z ){
            ans += getDistance(a[i],start);
            start = a[i];
        }
    }
    // 保留三位小数
    cout << fixed << setprecision(3) << ans << endl;

}

int main() {
#if defined(__APPLE__) || defined(__WIN32__ )
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

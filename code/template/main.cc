#include <iostream>
#include <cstring>
using namespace std;
int a[105][105];
int sum[105][105];
int n, m;
// check the sum of the rectangle
bool checkSum(int width){

    for(int i = 1; i <= n - width; ++i){
        for(int j = 1; j <= m - width; ++j){
            int x = i + width - 1;
            int y = j + width - 1;
            if(x > n || y > m) continue;
            int s = sum[x][y] - sum[x][j-1] - sum[i-1][y] + sum[i-1][j-1];
            if(s == width * width) return true;
        }
    }
    return false;
}

void run() {
    // 4 4
    // 0 1 1 1
    // 1 1 1 0
    // 0 1 1 0
    // 1 1 0 1 

    memset(sum, 0, sizeof(sum));
    memset(a, 0, sizeof(a));
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) cin >> a[i][j];
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j];
        }
    }

    
    // for(int i = 1; i <= n; ++i){
    //     for(int j = 1; j <= m; ++j){
    //         cout<<sum[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    int l = 0 , r = min(n, m);
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if(checkSum(mid)) l = mid;
        else r = mid - 1;
    }
    cout<<l <<endl;
        


}

int main() {
#if defined(__APPLE__) || defined(__WIN32__ )
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

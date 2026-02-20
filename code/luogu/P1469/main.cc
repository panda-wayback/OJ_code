#include <bits/stdc++.h>
using namespace std;

void run(){
    // 9
    // 2 2 1 3 3 3 2 3 1
    int n;
    cin >> n;
    int res = 0,x;
    for(int i = 0 ; i < n; ++i){
        cin>>x;
        res ^= x;
    }
    cout<< res <<endl;
}

int main() {
#if defined(__APPLE__) || defined(__WIN32__ )
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

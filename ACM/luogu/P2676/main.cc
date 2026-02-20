#include <bits/stdc++.h>
using namespace std;

void run(){
    int n, b;
    cin >> n >> b;
    vector<int > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin() ,a.end() );
    int ans = 0;
    for(int i = a.size() - 1 ; i >=0 ; --i){
        ans += a[i];
        if(ans >= b){
            cout << a.size() - i << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
#if defined(__APPLE__) || defined(__WIN32__ )
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

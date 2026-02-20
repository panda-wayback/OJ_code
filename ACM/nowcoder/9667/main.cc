#include <bits/stdc++.h>
using namespace std;

void run(){
    string x,y;
    cin>>x>>y;
    if(x.size() > y.size()){
        swap(x,y);
    }
}

int main() {
#if defined(__APPLE__)  || defined(__WIN32__ )
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

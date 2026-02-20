#include <bits/stdc++.h>
using namespace  std;

int dfs(int depth ,int index, vector<int > &arr , vector<int > &result ){
    
    if(depth == 3){
        
        if( (result[0] + result[1] > result[2]) &&
             (result[2] + result[1] > result[0]) &&
             (result[0] + result[2] > result[1])  )
            return 4;
        if( (result[0] + result[1] >= result[2]) &&
             (result[2] + result[1] >= result[0]) &&
             (result[0] + result[2] >= result[1])  )
            return 2;
        return 1;
    }
    int tag = 1;
    for(int i = index ; i < arr.size() ; i++){
        result[depth] = arr[i];
        tag  |= dfs(depth + 1 , i + 1, arr,result);
    }
    return tag;
}

void run(){
    int n;
    n = 4;
    vector<int > arr(n) ,result(n);
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int num = dfs(0 ,0, arr ,result);
    if(num >= 4  ){
        cout<<"TRIANGLE"<<endl;
    }else if(num >= 2){
        cout<<"SEGMENT"<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

}


int main() {
#if defined(__APPLE__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}
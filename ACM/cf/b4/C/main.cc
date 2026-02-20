#include <bits/stdc++.h>
using namespace std;


void run(){
    int n;
    cin>>n;
    string temp_str;
    map<string ,int > tag;
    for(int i= 0 ; i < n; i ++){
        cin>>temp_str;
        if(tag[temp_str] == 0){
            cout<<"OK"<<endl;
        }else{
            cout<<temp_str<<tag[temp_str]<<endl;
        }
        tag[temp_str] += 1;
    }
    

}
int main(){
    #if defined(__APPLE__)
        freopen("./slyar.in", "r+", stdin);
        freopen("./slyar.out", "w+", stdout);
    #endif
    run();
}
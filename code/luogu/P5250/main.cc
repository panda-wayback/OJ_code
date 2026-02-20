#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAX_LEN = 1000*1000;

void run() {
    int n;
    cin >> n;
    set<int> myset;
    set<int> myset_op;
    for (int i = 0,x,y; i < n; i++){
        cin>> x >> y;
        if(x == 1){
            if(myset.find(y) == myset.end()){
                myset.insert(y);
                myset_op.insert(-y);
            }
            else{
                cout << "Already Exist" << endl;
            }
        }
        else{
            auto lower = myset.lower_bound(y);
            auto lower_op = myset_op.lower_bound(-y);
            // cout<< "lower: " << *lower << " lower_op: " << *lower_op <<endl;

            if(lower_op != myset_op.end() &&  abs(-(*lower_op) -y) <=  abs(y - (*lower))  ){
                cout << -(*lower_op) <<endl;
                // 删除lower
                int s = *lower_op;
                myset_op.erase(s);
                myset.erase(-s);
            }
            else if(lower != myset.end()){
                cout << *lower <<endl;
                // 删除lower
                int s = *lower;
                myset.erase(s);
                myset_op.erase(-s);
            }
            else{
                cout << "Empty"<<endl;
            }
            // cout<<"myset: "<< myset.size()<<" myset_op: "<< myset_op.size()<<endl;

        }
       
    }
    cout << endl;
}

int main() {
#if defined(__APPLE__) || defined(__WIN32__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

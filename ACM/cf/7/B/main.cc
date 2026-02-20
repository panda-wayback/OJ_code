#include <bits/stdc++.h>
using namespace std;
void run();

int main() {
#if defined(__APPLE__)
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

int cnt = 0;

//这个玩意好像很快
unordered_map<int , list<int > > cnt_tag_map;

/**
 * 
 * 
 * */
void alloc(vector<int> &arr) {
    int len;
    cin >> len;
    int tag = 0;
    int index = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            tag += 1;
        } else if (arr[i] != 0) {
            tag = 0;
        }
        if (tag == len) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        cout << ++cnt  << endl;
        for (int i = index; i > index - len; --i) {
            arr[i] = cnt;
            cnt_tag_map[cnt].push_back(i);
        }

    } else {
        cout << "NULL" << endl;
    }
}

/**
 * 清空某个代码块 , map 存放代码块的list 这样不需要遍历整个内存块 
 */
void erase(vector<int> &arr) {
    int index;
    cin >> index;
    bool tag = false;
    if(index > 0 ){
        while(!cnt_tag_map[index].empty() ) {
            arr[ cnt_tag_map[index].back() ] = 0;
            cnt_tag_map[index].pop_back();
            tag = true;
        }
    }

    if(!tag){
        cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
    }
}

void defragment(vector<int> &arr) {
    cnt_tag_map.clear();
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            int index = i;
            while (arr[i] == 0 && i < arr.size()) {
                i++;
            }
            while (arr[i] != 0 && i < arr.size()) {
                swap(arr[index] , arr[i]);
                cnt_tag_map[arr[index]].push_back(index);
                ++i;
                ++index;
            }
        }else{
            cnt_tag_map[arr[i]].push_back(i);
        }
    }
    /*
    cout<<"defragment ";
    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<' ';
    }cout<<endl;
    */

}

void run() {
    int T, m;
    cin >> T >> m;

    vector<int> arr(m);
    while (T--) {
        string order;
        int index;
        cin >> order;

        if (order[0] == 'a') {
            alloc(arr);
        } else if (order[0] == 'e') {
            erase(arr);
        } else {
            defragment(arr);
        }
    }
}
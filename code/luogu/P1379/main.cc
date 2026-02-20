#include <iostream>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

// 设计八数码结构
struct Eight {
    int a[3][3];
    int x, y;
    int step = 0;
    Eight() {
        memset(a, 0, sizeof(a));
        x = y = 0;
        step = 0;
    }
    Eight(const Eight &e) {
        memcpy(a, e.a, sizeof(a));
        x = e.x;
        y = e.y;
        step = e.step;
    }
    Eight &operator=(const Eight &e) {
        memcpy(a, e.a, sizeof(a));
        x = e.x;
        y = e.y;
        step = e.step;
        return *this;
    }
    Eight(const string &str){
        int cnt = 0;
        for (int i = 0; i < 9; ++i) {
            a[i / 3][i % 3] = str[i] - '0';
            if (a[i / 3][i % 3] == 0) {
                x = i / 3;
                y = i % 3;
            }
        }
        step = 0;
    }
    void moveUp() {
        if (x == 0) {
            return;
        }
        swap(a[x][y], a[x - 1][y]);
        --x;
        ++step;
    }
    void moveDown() {
        if (x == 2) {
            return;
        }
        swap(a[x][y], a[x + 1][y]);
        ++x;
        ++step;
    }
    void moveLeft() {
        if (y == 0) {
            return;
        }
        swap(a[x][y], a[x][y - 1]);
        --y;
        ++step;
    }
    void moveRight() {
        if (y == 2) {
            return;
        }
        swap(a[x][y], a[x][y + 1]);
        ++y;
        ++step;
    }
    
    bool operator==(const Eight &e) const {
        return memcmp(a, e.a, sizeof(a)) == 0;
    }
    bool operator<(const Eight &e) const {
        return memcmp(a, e.a, sizeof(a)) < 0;
    }
    bool operator>(const Eight &e) const {
        return memcmp(a, e.a, sizeof(a)) > 0;
    }
    bool operator!=(const Eight &e) const {
        return memcmp(a, e.a, sizeof(a)) != 0;
    }
    bool operator<=(const Eight &e) const {
        return memcmp(a, e.a, sizeof(a)) <= 0;
    }
    bool operator>=(const Eight &e) const {
        return memcmp(a, e.a, sizeof(a)) >= 0;
    }
    int cmpDiff(const Eight &e) const {
        int cnt = 0;
        for (int i = 0; i < 9; ++i) {
            if (a[i / 3][i % 3] != e.a[i / 3][i % 3]) {
                ++cnt;
            }
        }
        return cnt;
    }
    void print() const {
        for (int i = 0; i < 3; ++i) {
            printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
        }
    }
    int hash() const {
        int ret = 0;
        for (int i = 0; i < 9; ++i) {
            ret = ret * 10 + a[i / 3][i % 3];
        }
        return ret;
    }
    int getStep() const {
        return step;
    }
};

void run(){
    // input  283104765
    // Eight
    // 2 8 3
    // 1 0 4
    // 7 6 5
    // output 4
    string str;
    cin >> str;
    Eight e(str);
    Eight target("123804765");
    // bfs
    // Priority queue
    // 优先队列
    // 优先队列的优先级由cmp函数决定
    // 优先队列的top()函数返回优先级最高的元素
    // 优先队列的pop()函数删除优先级最高的元素
    // 优先队列的push()函数插入一个元素
    // 优先队列的size()函数返回队列中元素的个数
    // 优先队列的empty()函数返回队列是否为空
    // 优先队列的clear()函数清空队列
    // 优先队列的定义
    // priority_queue<pair<int, Eight> >
    // int 从小到大
    // Eight 从小到大
    priority_queue<pair<int, Eight>, vector<pair<int, Eight> >, greater<pair<int, Eight> > > q;
    q.push(make_pair(0, e));
    map<int, int> lessStep;
    map<int,bool> vis;
    lessStep[e.hash()] = 0;
    int maxStep = 30;
    while (!q.empty()) {
        Eight now = q.top().second;
        q.pop();

        if(!vis[now.hash()]){
            vis[now.hash()] =  true;
            // cout<<"asdasdasd ### "<<endl;
        }
        else if (lessStep[now.hash()] <=  now.getStep()  ) {
            //cout<<"asdasd   "<<now.hash()<<' '<<lessStep[now.hash()]  <<' '<<now.getStep()<<endl;
            continue;
        }

        // cout<<q.size()<<" now: "<< now.hash() <<"  step: "<<now.getStep()<<' '<<lessStep[now.hash()] <<  ' '<<(now.cmpDiff(target)+now.getStep()) << endl; 

        lessStep[now.hash()] = now.getStep();
        if (lessStep[now.hash()] > maxStep ) {
            continue;
        }
        if (now == target) {
            //cout << "end " << lessStep[now.hash()]<<' '<<(&now)<<' ' << now.getStep() << endl;
            cout<<now.getStep()<<endl;
            maxStep = now.getStep();
            return;
        }

        Eight next = now;
        next.moveUp();
        // cout<<"moveUp "<<now.getStep()<<' '<<(&now)<<' '<< next.getStep()<<' '<<(&next)<<endl;

       
            q.push(make_pair((next.cmpDiff(target)+next.getStep()), next));
        
        next = now;
        next.moveDown();
        // cout<<"moveDown "<<now.getStep()<<' '<<(&now)<<' '<< next.getStep()<<' '<<(&next)<<endl;

       
            q.push(make_pair((next.cmpDiff(target)+next.getStep()), next));
        
        next = now;
        next.moveLeft();
        // cout<<"moveLeft "<<now.getStep()<<' '<<(&now)<<' '<< next.getStep()<<' '<<(&next)<<endl;

 
            q.push(make_pair((next.cmpDiff(target)+next.getStep()), next));
        
        next = now;
        next.moveRight();
        // cout<<"moveRight "<<now.getStep()<<' '<<(&now)<<' '<< next.getStep()<<' '<<(&next)<<endl;


            q.push(make_pair((next.cmpDiff(target)+next.getStep()), next));
        
        // while(!q.empty()){
        //     cout<<"####   "<<q.top().first<<' '<<q.top().second.hash()<<' '<<q.top().second.getStep()<<endl;
        //     q.pop();
        // }
        //return ;
    }
    cout<<lessStep[target.hash()]<<endl;
}

int main() {
#if defined(__APPLE__) || defined(__WIN32__ )
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

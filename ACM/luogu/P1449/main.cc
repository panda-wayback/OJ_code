#include <bits/stdc++.h>
using namespace std;

void run(){
    // input data
    // like : 10.28.30./*7.-@
    // . 为操作数的结束符号。
    string s;
    cin >> s;
    stack<int> st;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            // 读取数字
            double num = 0;
            while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                num = num * 10 + s[i] - '0';
                ++i;
            }
            st.push(num);
            --i;
        }
        else if(s[i] != '.' && s[i] != '@' ){
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            double ans = 0;
            if(s[i] == '+'){
                ans = a + b;
            }
            else if(s[i] == '-'){
                ans = b - a;
            }
            else if(s[i] == '*'){
                ans = a * b;
            }
            else if(s[i] == '/'){
                ans = b / a;
            }
            st.push(ans);
        }
    }

    cout<<fixed<<setprecision(0)<<st.top()<<endl;






}

int main() {
#if defined(__APPLE__) || defined(__WIN32__ )
    freopen("./slyar.in", "r+", stdin);
    freopen("./slyar.out", "w+", stdout);
#endif
    run();
}

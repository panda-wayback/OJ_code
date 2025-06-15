#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
private:
    // 树状数组类
    class BIT {
    private:
        vector<long long > tree;
        long long n;
        
    public:
        BIT(long long size) : n(size), tree(size + 1, 0) {}
        
        // 更新树状数组
        void update(long long index, long long delta) {
            while (index <= n) {
                tree[index] += delta;
                index += index & -index;
            }
        }
        
        // 查询前缀和
        long long query(long long index) {
            long long sum = 0;
            while (index > 0) {
                sum += tree[index];
                index -= index & -index;
            }
            return sum;
        }
    };
    
public:
    vector<long long > countGreaterBefore(vector<long long >& nums) {
        long long n = nums.size();
        vector<long long > result(n, 0);
        
        // 离散化处理
        vector<long long > sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        unordered_map<long long , long long > rank;
        for (long long i = 0; i < n; i++) {
            rank[sorted_nums[i]] = i + 1;
        }
        
        // 使用树状数组统计
        BIT bit(n);
        for (long long i = 0; i < n; i++) {
            long long current_rank = rank[nums[i]];
            // 查询比当前数字大的数量
            result[i] = i - bit.query(current_rank);
            // 更新树状数组
            bit.update(current_rank, 1);
        }
        
        return result;
    }
};

// 用于本地调试的函数
void run() {
    Solution solution;
    
    // 测试用例1
    // vector<long long > nums1 = {7, 5, 6, 4};
    // vector<long long > result1 = solution.countGreaterBefore(nums1);
    // cout << "测试用例1 [7,5,6,4] 的结果：" << endl;
    // for (long long i = 0; i < nums1.size(); i++) {
    //     cout << "数字 " << nums1[i] << " 前面有 " << result1[i] << " 个比它大的数字" << endl;
    // }
    // cout << endl;
    long long n;
    
    cin >> n;
    vector<long long > nums;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        nums.push_back(x);
    }
    vector<long long > result = solution.countGreaterBefore(nums);
    long long mi = 1, cheng = 2;
    long long mod = 1e9 + 7;
    long long res = 0 ;
    for (long long i = 1; i < n; i++) {
       
        res = (res + result[i] * mi) % mod;
        // cout<< res << " " << result[i] << " "<< mi << endl;
        mi = mi * cheng % mod;

    }
    // cout << endl;
    cout << res << endl;
    
}

int main() {
    // 本地调试时自动重定向输入输出
#if defined(__APPLE__) || defined(__WIN32__)
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    
    // 设置输出精度
    // cout << fixed << setprecision(6);
    
    // 运行测试
    run();
    
    return 0;
}

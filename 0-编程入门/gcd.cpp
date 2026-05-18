/*
 * 题目：求两个非负整数的最大公约数（GCD）
 * 思路：使用辗转相除法（欧几里得算法）
 *      核心：gcd(a, b) = gcd(b, a % b)，直到余数为 0，此时的除数就是答案
 *      不属于滑动窗口，是纯数学迭代/递归计算
 * 时间复杂度：O(log(min(a, b))) （对数级别，远快于 O(n)）
 * 空间复杂度：O(1) （仅使用常数变量，无额外空间）
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 函数：辗转相除法求最大公约数
    int gcd(int a, int b) {
        // 循环：当 b 不为 0 时，持续取余迭代
        while (b != 0) {
            int temp = a % b;  // 计算 a 除以 b 的余数
            a = b;             // 把原来的除数变成新的被除数
            b = temp;          // 把余数变成新的除数
        }
        // 当 b = 0 时，a 就是最大公约数
        return a;
    }
};

int main() {
    Solution sol;
    
    // 测试用例 1
    int ans1 = sol.gcd(48, 18);
    cout << "gcd(48, 18) = " << ans1 << endl; // 输出 6
    
    // 测试用例 2
    int ans2 = sol.gcd(100, 25);
    cout << "gcd(100, 25) = " << ans2 << endl; // 输出 25
    
    // 测试用例 3
    int ans3 = sol.gcd(7, 5);
    cout << "gcd(7, 5) = " << ans3 << endl; // 输出 1

    return 0;
}
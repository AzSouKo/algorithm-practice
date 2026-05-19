/*
 * LeetCode 3090 - 每个字符最多出现两次的最长子字符串
 * 难度：1329
 * 标签：滑动窗口 / 字符串/ 哈希表
 * 日期：2026-5-19
 * 思路：采用滑动窗口法，用左右指针维护窗口范围，通过count数组统计字符出现次数，右指针不断扩大窗口并更新字符计数，
 * 当当前字符出现次数超过2时移动左指针缩小窗口，始终保证窗口内所有字符出现次数≤2，同时更新最长合法子串长度。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> count(128, 0); // 记录每个字符出现的次数
        int left = 0, right = 0; // 滑动窗口的左右边界
        int maxLength = 0; // 记录最长子字符串的长度

        while (right < s.length()) {
            count[s[right]]++;
            while (count[s[right]] > 2) {
                count[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    // 测试用例
    // auto result = sol.functionName(...);
    // cout << result << endl;
    return 0;
}

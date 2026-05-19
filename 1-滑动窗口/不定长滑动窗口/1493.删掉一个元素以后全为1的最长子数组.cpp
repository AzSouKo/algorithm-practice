/*
 * LeetCode 1493 - 删掉一个元素以后全为1的最长子数组
 * 难度：1423
 * 标签：数组/滑动窗口/动态规划
 * 日期：2026-05-19
 * 思路：采用滑动窗口法，用左右指针维护窗口范围，通过计数器统计0的个数，右指针不断扩大窗口并更新计数，
 * 当0的个数超过1时移动左指针缩小窗口，始终保证窗口内0的个数≤1，同时更新最长合法子数组长度。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxlenth = 0;
        int left = 0, right = 0;
        int zeroCount = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            maxlenth = max(maxlenth, right - left);//强制删除1个数
            right++;
        }
        return maxlenth;
    }
};

int main() {
    Solution sol;
    // 测试用例
    // auto result = sol.functionName(...);
    // cout << result << endl;
    return 0;
}

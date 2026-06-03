/*
 * LeetCode #209 - 长度最小的子数组
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-06-02
 * 思路：使用滑动窗口技术，维护一个窗口，使得窗口内元素的和大于等于目标值。通过调整窗口的左右边界来找到最小长度的子数组。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int minSubArrayLen(int target, vector<int>& nums) {
        int n =nums.size();
        int ans = INT_MAX;
        int sum = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    Solution sol;
    
    return 0;
}
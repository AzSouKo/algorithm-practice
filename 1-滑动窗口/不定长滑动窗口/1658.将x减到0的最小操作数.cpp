/*
 * LeetCode #1658 - 将 x 减到 0 的最小操作数
 * 难度：1817中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-5-24
 * 思路：逆向思维，将问题转化为在数组中找到最长的子数组，使得该子数组的和为 sum(nums) - x。
 * 使用滑动窗口维护当前子数组的和，如果当前和大于目标值，则移动左指针缩小窗口；
 * 如果当前和等于目标值，则更新最大长度。最后返回数组长度减去最大长度，即为最小操作数。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x) return -1;
        int target = sum - x, currentSum = 0, maxLength = -1;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            currentSum += nums[right];
            while (currentSum > target) {
                currentSum -= nums[left++];
            }
            if (currentSum == target) {
                maxLength = max(maxLength, right - left + 1);
            }
        }
        return maxLength == -1 ? -1 : nums.size() - maxLength;
    }
};

int main() {
    Solution sol;
    
    return 0;
}
/*
 * LeetCode #2779 - 数组的最大美丽值
 * 难度：1638 中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-5-23
 * 思路：元素顺序对答案没有影响，可以先对数组排序原问题等价于：
 * 排序后，找最长的连续子数组，其最大值减最小值 ≤2k。由于数组是有序的，
 * 相当于子数组的最后一个数减去子数组的第一个数 ≤2k。
 * 我们只需考虑最左边的区间 [x−k,x+k] 和最右边的区间 [y−k,y+k]，如果这两个区间的交集不为空，那么选出的这些区间的交集就不为空。
 * 时间复杂度：O(n log n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int left = 0, right = 0, maxBeauty = 0;
        sort(nums.begin(), nums.end());
        while (right < nums.size()) {
            while (nums[right] - nums[left] > 2 * k) {
                left++;
            }
            maxBeauty = max(maxBeauty, right - left + 1);
            right++;
        }
        return maxBeauty;
    }
};

int main() {
    Solution sol;
    
    return 0;
}
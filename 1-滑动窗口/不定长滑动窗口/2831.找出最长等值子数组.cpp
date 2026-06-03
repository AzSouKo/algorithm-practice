/*
 * LeetCode #2831. 找出最长等值子数组
 * 难度：1976 中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-1
 * 思路：把每个数字 x 的出现位置做下标变形，变形差值 = 区间需要删除的非 x 数量；
    对每个 x 的变形数组用滑动窗口，满足删除数≤k 时，窗口长度就是同值最长子数组长度。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector <vector<int>> pos_lists(n+1);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            pos_lists[x].push_back(i-pos_lists[x].size());
        }
        int ans = 0;
        for (auto& pos : pos_lists) {
            int left = 0;
            for (int right = 0; right < pos.size(); right++) {
                while (pos[right] - pos[left] > k) {
                    left++;
                }
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    return 0;
}
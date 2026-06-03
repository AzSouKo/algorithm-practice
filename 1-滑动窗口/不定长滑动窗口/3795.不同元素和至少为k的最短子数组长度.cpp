/*
 * LeetCode #3795 - 不同元素和至少为k的最短子数组长度
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-06-02
 * 思路：在 nums 全为非负且数值范围 <= 1e5 时，用数组计数替代哈希表，
 *       维护窗口内不同元素之和，移动左右边界求最短长度。
 * 优化：
核心优化是把“窗口内元素计数”从哈希表改为*数组计数*：在数值范围 ≤ 1e5 且非负的前提下，
用 `vector<int> cnt` 直接索引，避免哈希开销与额外内存碎片。
窗口扩张时若某值首次出现就把该值加到“不同元素和”，收缩时若某值计数归零就从和中减去，
保证每个元素进出窗口各一次，整体仍是 O(n)。
同时只在需要时维护 `sum` 与窗口边界，去掉哈希查找/擦除的高常数操作，整体时间更稳、内存更紧凑。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)，U 为数组中的最大值
 */

#include <bits/stdc++.h>
using namespace std;

// 原始实现（保留作参考）
#if 0
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int ans = INT_MAX;             // 记录最小长度
        long long sum = 0;             // 窗口内不同元素之和
        unordered_map<int, int> cnt;   // 窗口内元素计数
        cnt.reserve(nums.size() * 2);
        cnt.max_load_factor(0.7f);
        int left = 0;
        for (int right = 0, n = static_cast<int>(nums.size()); right < n; right++) {
            int x = nums[right];
            int& c = cnt[x];
            if (c++ == 0) {
                sum += x;              // 首次出现才累加
            }
            while (sum >= k) {
                ans = min(ans, right - left + 1);
                int y = nums[left++];
                auto it = cnt.find(y);
                if (--it->second == 0) {
                    sum -= y;          // 移除最后一次出现的元素贡献
                    cnt.erase(it);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
#endif

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        if (n == 0) return -1;
        if (k <= 0) return 1;

        int maxVal = 0;
        for (int x : nums) {
            if (x > maxVal) maxVal = x;
        }

        vector<int> cnt(maxVal + 1, 0);
        long long sum = 0;
        int ans = INT_MAX;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            int x = nums[right];
            if (++cnt[x] == 1) {
                sum += x;
            }
            while (sum >= k) {
                ans = min(ans, right - left + 1);
                int y = nums[left++];
                if (--cnt[y] == 0) {
                    sum -= y;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

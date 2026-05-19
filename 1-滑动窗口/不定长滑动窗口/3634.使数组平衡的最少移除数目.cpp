/*
 * LeetCode 3634 - 使数组平衡的最少移除数目
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-05-19
 * 思路：
 * 时间复杂度：O(NlogN)
 * 空间复杂度：O(1)忽略排序的栈开销
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxLength = 0;
        int left = 0;
        for(int i=0;i<nums.size();i++){
            while(1LL * nums[left] * k < nums[i]){//1LL 防止溢出
                left++;
            }
            maxLength = max(maxLength, i - left + 1);
        }
        return nums.size() - maxLength;

    }
};

int main() {
    Solution sol;
    
    return 0;
}

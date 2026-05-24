/*
 * LeetCode #1838 - 最高频元素的频数
 * 难度：1876 中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-5-24
 * 思路：使用双指针技术，维护一个滑动窗口，使得窗口内的元素可以通过最多 k 次操作变成相同的元素
 * 时间复杂度：O(n log n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0,ans = 1;
        long long currentSum = 0;
        for(int right =1; right < nums.size(); right++){
            currentSum += (long long)(nums[right] - nums[right-1]) * (right - left);
            while(currentSum > k){
                currentSum -= nums[right] - nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    return 0;
}
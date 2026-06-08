/*
 * LeetCode #2962. 统计最大元素出现至少k次的子数组数目
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-8
 * 思路：使用滑动窗口技术，维护一个包含最大元素的窗口，当窗口内最大元素出现次数达到k时，计算满足条件的子数组数目。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int left = 0;
        int cnt = 0;
        int curmax = *max_element(nums.begin(), nums.end());
        for(int right = 0;right<nums.size();right++){
            if(nums[right]==curmax)cnt++;
            while (cnt>=k)//当最大元素出现的次数大于等于k时，移动左指针缩小窗口,为什么要加等于：因为当最大元素出现的次数等于k时，继续移动左指针缩小窗口，直到最大元素出现的次数小于k，此时窗口内最大元素出现的次数就不满足条件了，所以要加等于。
            {
                if(nums[left]==curmax)cnt--;
                left++;
                
            }
            
            ans += left;

        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    return 0;
}
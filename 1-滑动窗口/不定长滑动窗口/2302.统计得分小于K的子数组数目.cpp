/*
 * LeetCode #2302. 统计得分小于k的子数组数目
 * 难度：困难
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-7
 * 思路：有单调性。本题元素均为正数，所以子数组越长，分数越高；子数组越短，分数越低。这意味着只要某个子数组的分数小于 k，在该子数组内的更短的子数组，分数也小于 k。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        long long curSum=0;

        int left=0;
        for(int right = 0;right<nums.size();right++){
            curSum = curSum + nums[right];
            while(curSum*(right-left+1)>=k){
                curSum = curSum - nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    return 0;
}
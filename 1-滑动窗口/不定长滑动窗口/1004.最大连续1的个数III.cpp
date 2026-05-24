/*
 * LeetCode #1004 - 最大连续1的个数 III1004 - 最大连续1的个数 III
 * 难度：1656 中等
 * 标签：滑动窗口 / 数组 / 二分查找 /前缀和
 * 日期：2026-5-23
 * 思路：滑动窗口右指针不断右移，遇到 0 就消耗一次修改次数k，
 * 当k<0（修改次数用尽）时左指针右移回收可修改次数，持续更新最长全 1 子数组长度。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int longestOnes(vector<int>& nums, int k) {
     int left = 0, ans = 0;
     for(int right = 0;right<nums.size();right++){
        if(nums[right]==0)k--;
        while(k<0){
            if(nums[left]==0)k++;
            left++;
        }
        ans = max(ans,right-left+1);
     }   
     return ans;
    }

    int longestOnes2(vector<int>& nums, int k) {//更快的写法，思路一样
        int ret = 0;
        int zero = 0, right = 0, left = 0;
        while(right < nums.size())
        {
            if(nums[right] == 0)    zero++;
            while(zero > k)
                if(nums[left++] == 0) zero--;
            ret = max(right - left + 1, ret);
            right++;
        }
        return ret;
    }

};

int main() {
    Solution sol;
    
    return 0;
}
/*
 * LeetCode #713. 乘积小于k的子数组
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-06-06
 * 思路：由于子数组越长，乘积越大，越不能满足题目要求；反之，子数组越短，乘积越小，越能满足题目要求。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)return 0;//如果k<=1，那么没有任何子数组的乘积小于k，直接返回0

        int ans = 0;
        int product = 1;//记录当前窗口内的乘积
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            product *= nums[right];//窗口右端点向右移动，更新乘积

            while(product >= k){//如果当前窗口内的乘积不满足条件，那么窗口左端点向右移动，直到满足条件
                product /= nums[left];
                left++;
            }

            ans += right - left + 1;//当前窗口内的子数组数量是 right - left + 1
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    return 0;
}
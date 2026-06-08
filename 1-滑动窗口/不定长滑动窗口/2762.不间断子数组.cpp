/*
 * LeetCode #2762. 不间断子数组数目
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-7
 * 思路：最多维护3个数字（三种不同的数字比如123 456 789 ，如果有四个数字差值一定会大于2）
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int left = 0;
        map<int,int> cnt;//map会自动从小到大排序
        for(int right = 0;right<nums.size();right++){
            cnt[nums[right]]++;

            while(cnt.rbegin()->first - cnt.begin()->first > 2){
                cnt[nums[left]]--;
                if(cnt[nums[left]]==0){
                    cnt.erase(nums[left]);
                }
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
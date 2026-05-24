/*
 * LeetCode #1695 - 删除子数组的最大得分
 * 难度：1529 中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：YYYY-MM-DD
 * 思路：使用滑动窗口维护当前子数组的和，同时使用哈希表记录每个元素的出现次数，当出现重复元素时，移动左指针缩小窗口，直到没有重复元素为止。
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       unordered_map<int,int> cnt;
       int ans = 0;
       int sum = 0;
         int left = 0;
         for(int i=0;i<nums.size();i++){
             cnt[nums[i]]++;
             sum+=nums[i];
             while(cnt[nums[i]]>1){
                 cnt[nums[left]]--;
                 sum-=nums[left];
                 left++;
             }
             ans = max(ans,sum);
         }
         return ans;
    }

    int maximumUniqueSubarray2(vector<int>& nums) {
        // 另一种写法，思路一样,这题也可以用哈希集合维护窗口，cnt 只需要记录是否存在即可
       unordered_map<int,int> cnt;
       int ans = 0, sum = 0, left = 0;

         for(int x : nums){
             cnt[x]++;
             sum+=x;
             while(cnt[x]>1){
                 cnt[nums[left]]--;
                 sum-=nums[left];
                 left++;
             }
             ans = max(ans,sum);
         }
         return ans;
    }


};

int main() {
    Solution sol;

    return 0;
}

/*
 * LeetCode #2958 - 最多 k 个重复元素的最长子数组
 * 难度：1535 中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：YYYY-MM-DD
 * 思路：使用滑动窗口维护一个最多包含 k 个重复元素的子数组，通过哈希表记录每个元素的出现次数，
 * 当某个元素的出现次数超过 k 时，移动左指针缩小窗口。
 * 时间复杂度：O(n)
 * 空间复杂度：O(k)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        int ans = 0;
        int left = 0;
        for(int right = 0;right<nums.size();right++){
            cnt[nums[right]]++;
            while(cnt[nums[right]]>k){
                cnt[nums[left]]--;
                if(cnt[nums[left]]==0)cnt.erase(nums[left]);
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    return 0;
}
/*
 * LeetCode #2799. 统计完全子数组的数目
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-9
 * 思路：
 * 时间复杂度：O()
 * 空间复杂度：O()
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays1(vector<int>& nums) {//暴力解法
        unordered_set<int> s(nums.begin(),nums.end());
        int n = nums.size();//完全子数组的长度至少为s.size()
        int ans = 0;
        for(int i = 0;i<=nums.size()-s.size();i++){
            unordered_set<int> t;
            for(int j = i;j<nums.size();j++){
                t.insert(nums[j]);
                if(t.size()==s.size()){
                    ans++;
                }
            }
        }
        return ans;
    }

     int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int n = nums.size();//完全子数组的长度至少为s.size()
        int ans = 0;
        int left = 0;
        for(int right = 0;right<nums.size();right++){
            
            
            
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    return 0;
}
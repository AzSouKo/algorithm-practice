/*
 * LeetCode #
 * 难度：
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：
 * 思路：
 * 时间复杂度：O()
 * 空间复杂度：O()
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int left = 0;
        long long ans = 0;
        int pairs = 0;
        unordered_map<int,int> cntmap;
        for(int right =0;right < nums.size();right ++){
            int x = nums[right];
            pairs += cntmap[x];
            cntmap[x]++;

            while (pairs>=k)
            {   
                int y = nums[left];
                cntmap[y]--;
                pairs -= cntmap[y];
                left++;
            }
            ans += left;
        }
        return ans;

    }

    long long countGood2(vector<int>& nums, int k) {
        long long ans =0;
        unordered_map<int ,int >cnt;
        int pairs = 0;
        int left = 0;
        for(int x:nums){
            pairs += cnt[x]++;
            // 拆分理解：后置自增，先取值运算，再计数+1
            // cnt[x]：当前窗口中数字x已存在的数量
            // 新加入一个x，会和前面所有x各形成一对，新增对数 = cnt[x]
            while(pairs>=k){
                pairs -= --cnt[nums[left]];
                left ++;
            }
            ans +=left;
        }
        return ans;
    }

};

int main() {
    Solution sol;
    
    return 0;
}
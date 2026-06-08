/*
 * LeetCode #3258. 统计满足k约束的子字符串数目
 * 难度：eazy
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-7
 * 思路：滑动窗口，用cnt统计是否满足，越长越满足，ans += r-l+1。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int countKConstraintSubstrings(string s, int k) {
        int cnt[2]={};
        int left = 0,ans = 0;
        for(int right =0;right <s.size();right++){
            cnt[s[right]-'0']++;

            while(cnt[0]>k&&cnt[1]>k){
                cnt[s[left]-'0']--;
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
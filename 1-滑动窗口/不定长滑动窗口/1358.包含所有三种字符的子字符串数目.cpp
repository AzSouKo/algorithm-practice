/*
 * LeetCode #1358. 包含所有三种字符的子字符串数目
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-8
 * 思路：
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int numberOfSubstrings(string s) {
        int cnt[3]={};
        int ans = 0;
        int left = 0;
        for(int right =0;right<s.size();right++){
            cnt[s[right]-'a']++;
            while(cnt[0]>0 && cnt[1]>0 && cnt[2]>0){
                cnt[s[left]-'a']--;
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
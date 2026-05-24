/*
 * LeetCode #2730 - 找到最长的半重复子字符串
 * 难度：1520   中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-5-23
 * 思路：滑动窗口右指针右移，统计窗口内相邻重复字符对的数量，当超过 1 对时移动左指针收缩窗口，全程更新最长合法子串长度。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int longestSemiRepetitiveSubstring(string s) {
        int ans = 0;
        int left = 0;
        int cnt = 0;//记录当前窗口内重复元素的数量
        for(int right = 0;right<s.size();right++){
            if(right>0 && s[right]==s[right-1]){
                cnt++;
                while(cnt>1){
                    if(s[left]==s[left+1])cnt--;
                    left++;
                }
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
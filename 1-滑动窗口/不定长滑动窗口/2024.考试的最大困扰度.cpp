/*
 * LeetCode #2024 - 考试的最大困扰度
 * 难度：中等
 * 标签：滑动窗口 / 字符串 / 二分查找
 * 日期：2026-5-23
 * 思路：用滑动窗口维护区间，统计窗口内T、F数量，当两者均超过可修改次数k时收缩左边界，不断更新最长合法区间长度。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0;
        unordered_map<bool,int> cnt;//也可以用数组cnt[2]，统计 T 和 F 的出现次数
        int left = 0;
        for(int right = 0;right<answerKey.size();right++){
            cnt[answerKey[right]=='T']++;
            while(cnt[true]>k && cnt[false]>k){
                cnt[answerKey[left]=='T']--;
                //由于 T 和 F 的 ASCII 值除以 2 后的奇偶性不同，也就是它们二进制的次低位不同，可以改为统计二进制次低位。
                //cnt[answerKey[left] >> 1 & 1]--;
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
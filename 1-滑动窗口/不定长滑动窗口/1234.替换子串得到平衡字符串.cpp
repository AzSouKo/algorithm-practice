/*
 * LeetCode #1234.替换子串得到平衡字符串
 * 难度：简单 / 中等 / 困难
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-6
 * 思路：简要说明解题思路（定长/不定长？用什么数据结构维护窗口？）
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int balancedString(string s) {
        int cnt['X']{};
        for(char c:s){
            cnt[c]++;
        }

        int n = s.size(),m = n/4;
        if(cnt['W']==m&&cnt['E']==m&&cnt['R']==m&&cnt['Q']==m)
        {
            return 0;
        }

        int ans =n,left = 0;
        for(int right = 0;right < n; right++){
            cnt[s[right]]--;
            while(cnt['Q']<=m&&cnt['E']<=m&&cnt['W']<=m&&cnt['R']<=m){
                ans = min(ans,right-left +1);
                cnt[s[left]]++;
                left++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    // 测试用例
    // auto result = sol.functionName(...);
    // cout << result << endl;
    return 0;
}
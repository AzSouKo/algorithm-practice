/*
 * LeetCode #2516 - 每种字符至少取k个
 * 难度：1948 中等
 * 标签：滑动窗口 / 字符串 / 哈希表
 * 日期：2026-5-24
 * 思路：使用双指针技术，维护一个滑动窗口，使得窗口外的每个字符的出现次数都不小于 k
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int takeCharacters(string s, int k) {
        int left = 0;
        int ans = s.size();
        unordered_map<char, int> charCount;
        charCount['a'] = 0;
        charCount['b'] = 0;
        charCount['c'] = 0;
        for (char c : s) {
            charCount[c]++;
        }
        for (const auto &p : charCount) {
            if (p.second < k) {
                return -1; // 如果有任何字符的出现次数小于 k，直接返回 -1
            }
        }
        for (int right = 0; right < s.size(); right++) {
            charCount[s[right]]--;
            while (charCount[s[right]] < k) {
                charCount[s[left]]++;
                left++;
            }
            ans = min(ans, static_cast<int>(s.size()) - (right - left + 1)); // 更新最小长度
        }
        return ans;
    }
    
    
    //优化方案：使用数组代替哈希表，减少空间开销，并且直接访问字符对应的索引位置，提升效率。
    
    int takeCharacters2(string s, int k) {// 方法二：双指针+数组
        int cnt[3]{};// 统计每个字母的总数
        for (char c : s) {
            cnt[c - 'a']++; // 一开始，把所有字母都取走
        }
        if (cnt[0] < k || cnt[1] < k || cnt[2] < k) {
            return -1; // 字母个数不足 k
        }

        int mx = 0, left = 0;
        for (int right = 0; right < s.length(); right++) {
            int c = s[right] - 'a';
            cnt[c]--; // 移入窗口，相当于不取走 c
            while (cnt[c] < k) { // 窗口之外的 c 不足 k
                cnt[s[left] - 'a']++; // 移出窗口，相当于取走 s[left]
                left++;
            }
            mx = max(mx, right - left + 1);
        }
        return s.length() - mx;
    }


};

int main() {
    Solution sol;
    
    return 0;
}
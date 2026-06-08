/*
 * LeetCode #3325 - 字符至少出现k次的子字符串
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-8
 * 思路：越长约合法：使用双指针技术，维护一个滑动窗口，使得窗口内的每个字符的出现次数都不小于 k
 * 时间复杂度：O(n)
 * 空间复杂度：O(1) 或 O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        unordered_map<char, int> charCount;
        int left = 0;
        int ans = 0;
        
        for(int right = 0; right < s.size(); right++) {
            charCount[s[right]]++;
            while (charCount[s[right]] >= k) {
                charCount[s[left]]--;
                left++;
            }
            ans += left; // 更新答案，当前窗口内的子字符串数量
        }   
        return ans;
    }
    int numberOfSubstrings2(string s, int k) {
        // 优化方案：使用数组代替哈希表，减少空间开销，并且直接访问字符对应的索引位置，提升效率。
        int cnt[26]{}; // 统计每个字母的出现次数
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            cnt[s[right] - 'a']++;
            while (cnt[s[right] - 'a'] >= k) {
                cnt[s[left] - 'a']--;
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
/*
 * LeetCode #3298. 统计重新排列后包含另一个字符串的子字符串数目 II
 * 难度：困难
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-06-11
 * 思路：当当前窗口合法（less=0）时，不断右移左指针、剔除左侧字符，直到窗口不再满足条件；
 * 同时实时更新字符差异计数diff和不足字符数less，最终确定以当前右端点结尾的所有合法子串数量。
 * 用滑动窗口维护区间，通过 diff 记录字符数量差、less 标记缺失字符种类，
 * 找到每个右端点对应的最靠左合法边界，累加所有合法子串数量。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        if(word1.size() < word2.size()) {
            return 0;
        }//如果 word1 的长度小于 word2 的长度，那么无论如何重新排列 word1 都无法包含 word2，因此直接返回 0。

        int diff[26]{}; 
        for(char c : word2) {
            diff[c - 'a']++;
        }//首先遍历 word2，统计每个字符的出现次数，并将这些次数存储在 diff 数组中。
        // 对于 word2 中的每个字符 c，我们将 diff[c - 'a'] 的值减 1，
        // 这样 diff 数组就记录了 word1 中每个字符相对于 word2 的差异。

        int less = 0; // 当前窗口内有 less 个字符的出现次数比 word2 中对应字符的出现次数少
        for(int d:diff) {
            if(d>0){
                less++;//统计 diff 数组中大于 0 的元素个数，表示当前窗口内有多少个字符的出现次数比 word2 中对应字符的出现次数多。
            } 

        }
        long long ans = 0;
        int left = 0;
        for(char c:word1){
            diff[c - 'a']--; // right 移入窗口，更新 diff 数组
            if(diff[c - 'a'] == 0) {
                less--;
            }
        
            while(less == 0 ) {
            char out_char = word1[left++]-'a'; // left 指向的字符
            if(diff[out_char] == 0) {
                less++;
            }
            diff[out_char]++; // left 移出窗口，更新 diff 数组
            
        }
        ans += left; // 当前窗口内所有字符的出现次数都不比 word2 中对应字符的出现次数少，那么以 right 结尾的合法子字符串的数量就是 left 的值
        }
    return ans;

};

int main() {
    Solution sol;
    
    return 0;
}
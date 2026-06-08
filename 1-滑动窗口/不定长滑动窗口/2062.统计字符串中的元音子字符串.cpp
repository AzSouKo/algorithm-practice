/*
 * LeetCode #2062 - 统计字符串中的元音字母字符串

 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-06-8
 * 思路：使用滑动窗口技术，维护一个窗口，使得窗口内的每个字符都是元音字母
 * 右指针无脑扩展，左指针寻找刚好不满足条件的边界，两者之差即为答案
 * 想象你在玩一个“集齐5种元音卡牌”的游戏。
    start：你当前这局游戏的起始发牌位置。
    left：为了集齐5种卡牌，你最少需要保留的牌数（即最小合法窗口的左边界）。
    right：你当前正在摸的新牌。
    当 while(vowels.size() == 5) 循环结束时，意味着你把 left 往右推，直到刚好少了一种卡牌（不满足条件了）。
    此时，left 指向的位置，就是“刚好凑齐5种卡牌”的最左侧边界。
    优化：可以用数组代替哈希表，空间复杂度从 O(5) 降到 O(1)，但代码会稍微复杂一些。
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
#include <bits/basic_string.h>
using namespace std;

class Solution {
static constexpr string_view VOWELS = "aeiou";

public:
    int countVowelSubstrings(string word) {
        unordered_map<char,int> vowels;
        int left = 0;//最小合法窗口的左边界
        int ans = 0;
        int start = 0;// start记录当前窗口内第一个元音字母的位置
        for (int right = 0; right < word.size(); right++) {
         
            char ch = word[right];
            if(!VOWELS.contains(ch)){
                vowels.clear();
                start = left = right + 1;
                continue;
            }

            vowels[ch]++;
            while(vowels.size() == 5){
                char leftChar = word[left];
                vowels[leftChar]--;
                if(vowels[leftChar] == 0){
                    vowels.erase(leftChar);
                }
                left++;
            }

            ans += left - start;
          
        }
        
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    return 0;
}   
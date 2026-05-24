/*
 * LeetCode 3 - 无重复字符的最长子串
 * 难度：中等 
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-5-19
 * 思路：方法一：queue+unordered_map     方法二：双指针+unordered_map   
 * 时间复杂度：O(n)
 * 空间复杂度：O(k)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    /*方法一：queue+unordered_map
    这种方法利用了队列来维护当前的子串，并使用哈希表来快速检查字符是否已经存在于当前子串中。每当遇到重复字符时，就从队列头部弹出元素，直到把之前那个重复的旧字符移除为止。最后将当前的新字符加入队列，并更新最大长度。
    
    int lengthOfLongestSubstring(string s){
    unordered_map<char,bool> hash_map;
    queue<char> q;
    size_t max_num=0,ans=0;
    for(int i=0;i<s.size();i++){
        
        if(hash_map[s[i]]==0){
        q.push(s[i]);
        hash_map[s[i]]=1;
        max_num++;
        
        }

        else 
        {
            while (!q.empty()&&q.front() != s[i])
            {
                hash_map[q.front()] = 0;
                q.pop();
                max_num--;
            }

            if (!q.empty())
            {
                hash_map[q.front()] = 0; // 移除旧的那个
                q.pop();
                max_num--;
                q.push(s[i]);
                hash_map[s[i]]=1;
                max_num++;
            }
        }
        ans = max(ans, q.size()); // 用历史最大值 ans 和当前大小比较
    }
    return static_cast<int>(ans);
    }
    
    核心思想：利用队列（Queue）作为“滑动窗口”，保证队列内的字符始终没有重复。
    入队逻辑：遍历字符串，如果当前字符没在哈希表中标记过，直接加入队列并标记为已存在。
    出队与收缩：如果遇到重复字符，就从队列头部不断弹出元素（并在哈希表中取消标记），直到把之前那个重复的旧字符移除为止。最后将当前的新字符加入队列。
    记录结果：每次操作后，用队列的实时长度更新历史最大长度 ans。
    */


    /*方法二：双指针+unordered_map
    这种方法使用两个指针（left 和 right）来维护一个滑动窗口，并使用哈希表来记录窗口内字符的出现情况。当遇到重复字符时，移动左指针来收缩窗口，直到移除掉之前那个重复的旧字符。每次移动右指针时，更新最大长度。
    */
    int lengthOfLongestSubstring(string s){
    
        vector<int>lastPos(128,-1); // 记录每个字符上次出现的位置，初始化为-1
        int ans=0;
        int left=-1; // 左指针初始化为-1，表示窗口开始前的位置

        for(int right=0;right<s.size();right++){
            char c=s[right];
            if(lastPos[c]>left){ // 如果当前字符上次出现的位置在左指针右边，说明有重复
                left=lastPos[c]; // 移动左指针到上次出现位置的右边
            }
            lastPos[c]=right; // 更新当前字符的最新位置
            ans=max(ans,right-left); // 更新最大长度
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

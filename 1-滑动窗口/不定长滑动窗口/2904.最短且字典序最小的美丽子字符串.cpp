/*
 * LeetCode #2
 * 难度：简单 / 中等 / 困难
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：YYYY-MM-DD
 * 思路：用滑动窗口找到所有包含至少 k 个 1 的子串，从中保留最短、字典序最小的那个。
 * 时间复杂度：O(n2)
 * 空间复杂度：O(n)
 * 统计 1 必须写 s[right] == '1'
    字符串不能直接用 [] 赋值（未初始化会崩溃）
    滑动窗口移动左指针时，要更新 1 的计数
    答案第一次赋值要判断 empty()，否则永远不更新
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   string shortestBeautifulSubstring(string s, int k) {
        string ans="";//初始化
        int left =0, n = 0;
        n =s.size();
        int cnt = 0;

        for(int right = 0;right < n;right ++){
            if(s[right]=='1')cnt++;
            while(cnt>=k){
                string temp = s.substr(left,right-left+1);

                if(ans.empty()||temp.size()<ans.size()||(temp.size()==ans.size()&&temp<ans)){
                    ans = temp;//3. 更新答案：更短 或 同长度字典序更小
                }
                
                if(s[left]=='1')cnt--;//收缩时减少1
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
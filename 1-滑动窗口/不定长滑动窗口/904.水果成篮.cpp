/*
 * LeetCode #904 - 水果成篮
 * 难度：1516 中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期: 2026-5-23
 * 思路：不定长用滑动窗口，左右指针维护一个最多含 2 种水果的窗口，
 * 右指针不断右移加入水果，若种类超过 2 就移动左指针缩小窗口、移除多余种类，全程记录窗口的最大长度就是答案。
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    int ans =0;
    unordered_map <int,int> cnt;
    int left = 0 ;
    for(int right = 0;right<fruits.size() ;right++){
        
        cnt[fruits[right]]++;
        while(cnt.size()>2){
            cnt[fruits[left]]--;
            if(cnt[fruits[left]]==0)cnt.erase(fruits[left]);
            left++;
        }
        ans = max(ans,right-left+1);
    }
    
    return ans;

    }


};

int main() {
    Solution Sol;
    // 测试用例
    // auto result = sol.functionName(...);
    // cout << result << endl;
    return 0;
}

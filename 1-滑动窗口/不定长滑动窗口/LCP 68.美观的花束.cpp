/*
 * LeetCode #LCP 68. 美观的花束
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-8
 * 思路：
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        int ans = 0;
        int left = 0;
        unordered_map<int,int>cntMap;
        for(int right = 0;right<flowers.size();right++){
            cntMap[flowers[right]]++;

            while(cntMap[flowers[right]]>cnt){
                cntMap[flowers[left]]--;
                left++;
                if(cntMap[flowers[left]]==0){
                    cntMap.erase(flowers[left]);
                }
            }
            ans +=  right - left + 1;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    return 0;
}
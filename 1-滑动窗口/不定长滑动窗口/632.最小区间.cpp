/*
 * LeetCode #632. 最小区间
 * 难度：困难
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-06-06
 * 思路：把「每个列表至少有一个数包含在其中」的区间叫做合法区间。
    先求出最左边的合法区间，然后求出第二个合法区间，第三个合法区间，依此类推。
    比如示例 1，最左边的合法区间是 [0,5]。
    枚举所有合法区间的左端点，或者枚举所有合法区间的右端点。其中第一个最短的合法区间就是答案。
 * 时间复杂度：O()
 * 空间复杂度：O()
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //把这个二维数组转化为一个一维数组，记录每个数来自哪个列表
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                pairs.emplace_back(nums[i][j], i);
            }
        }
        //按照数值排序
        sort(pairs.begin(), pairs.end());
        //维护一个滑动窗口，记录窗口内每个列表的数量
        int ansl= pairs[0].first, ansr = pairs.back().first;//初始区间是整个数组

        int empty = nums.size();//记录窗口内没出现的列表
        
        vector<int> cnt(empty, 0);//记录窗口内每个列表的数量
        int left = 0;

        for(int right =0;right <pairs.size();right++){
            if(cnt[pairs[right].second]++ == 0)empty--;//如果这个列表之前没有出现过，那么empty-1


            while(empty == 0){

                if(empty == 0 && (pairs[right].first - pairs[left].first < ansr - ansl || (pairs[right].first - pairs[left].first == ansr - ansl && pairs[left].first < ansl))){
                ansl = pairs[left].first;
                ansr = pairs[right].first;
                /*先把窗口缩到不合法（empty≠0），再去判断答案
                  → 此时窗口已经不满足条件了，永远不会更新答案！
                 正确逻辑：先判断答案 → 再缩窗口
                必须在窗口still合法（empty=0）的时候记录答案，再去移动 left 缩小。
                */
            }

                cnt[pairs[left].second]--;//窗口左端点向右移动，更新这个列表的数量
                if(cnt[pairs[left].second] == 0)empty++;//如果这个列表之前出现过，现在没有了，那么empty+1
                left++;
            
            }


        }

        return {ansl, ansr};

    }
    
};

int main() {
    Solution sol;
    
    return 0;
}
/*
 * LeetCode #2271 - 棋子覆盖最多的白色砖块数
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 二分查找 / 前缀和
 * 日期：2026-06-02
 * 思路：首先按照砖块的起始位置排序，然后使用滑动窗口来维护当前覆盖的砖块数。对于每个砖块，计算地毯的左边界，并调整窗口的左边界以确保覆盖范围正确。最后更新最大覆盖数。
 * 时间复杂度：O(nLogn)
 * 空间复杂度：O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int ans = 0;
        int cover=0;
        int left = 0;
        sort(tiles.begin(), tiles.end());// 按照砖块的起始位置排序
        for(auto& tile : tiles) {
           int tl = tile[0], tr = tile[1];
           cover += tr - tl + 1;// 当前覆盖的砖块数
           int carpetleft = tr - carpetLen + 1;// 地毯的左边界
           while (tiles[left][1] < carpetleft) {
               cover -= tiles[left][1] - tiles[left][0] + 1;// 移除不被地毯覆盖的砖块数
               left++;
           }
           int uncover = max(0, carpetleft - tiles[left][0]);// 当前地毯覆盖的砖块数
           ans = max(ans, cover - uncover);// 更新最大覆盖数

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

/*
 * LeetCode #2875.无限数组的最短子数组
 * 难度：中等
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-6
 * 思路：使用滑动窗口技术，结合循环数组的特性，通过前缀和来优化查找过程
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minSizeSubarray(vector<int>& nums, int target) {
        int ans = INT_MAX, left = 0, sum = 0;
        vector<int> infinite_nums;
        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = target % total_sum;//关键步骤，因为我们只需要找到一个子数组的和等于 rem 的最短长度，剩下的部分可以通过完整的循环来补齐
        infinite_nums.insert(infinite_nums.end(), nums.begin(), nums.end());
        infinite_nums.insert(infinite_nums.end(), nums.begin(), nums.end());
        for (int right = 0; right < infinite_nums.size(); right++) {
            sum += infinite_nums[right];
            while (sum > rem) {
                sum -= infinite_nums[left];
                left++;
            }
            if (sum == rem) {
                ans = min(ans, right - left + 1);
            }
        }
        return ans == INT_MAX ? -1 : ans+(target/total_sum)*nums.size();
    }


    // 另一种写法,省时间省空间
    int minSizeSubarray2(vector<int>& nums, int target) {

    int n = nums.size();
    long long total = accumulate(nums.begin(), nums.end(), 0LL);
    
    int ans = INT_MAX;
    long long sum = 0;
    int left = 0;
    long long full = target / total;  // 完整圈数
    long long rem = target % total;   // 剩余需要匹配的和

    // 如果余数为0，说明刚好凑整圈，直接返回
    if (rem == 0) return full * n;

    // ========== 空间 O(1) 核心：不建数组，用 % 循环 ==========
    for (int right = 0; right < 2 * n; right++) {
        sum += nums[right % n];  // 模拟循环数组
        
        // 收缩窗口
        while (sum > rem) {
            sum -= nums[left % n];
            left++;
        }
        
        // 更新最短长度
        if (sum == rem) {
            ans = min(ans, right - left + 1);
        }
    }
    return ans == INT_MAX ? -1 : ans + full * n;
    }
/*
删掉了 vector<int> infinite_nums → 省空间
删掉了两次 insert → 省时间
用 right%n 模拟循环数组 → 最高效
逻辑更干净，无多余操作
*/

};

int main() {
    Solution sol;
    
    return 0;
}
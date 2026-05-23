/*
 * LeetCode #1208 - 尽可能使字符串相等
 * 难度：中等
 * 标签：滑动窗口 / 二分查找 / 前缀和 
 * 日期：2026/05/21
 * 思路：使用滑动窗口寻找总开销不超过 maxCost 的最长子数组
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans=0,left=0;
        int cost=0;
        int n=s.size();
        vector<int> kx(n);
        for(int i=0;i<n;i++){
            kx[i]=abs(s[i]-t[i]);
        }

        for(int i=0;i<n;i++){
            cost+=kx[i];

            while(maxCost<cost){
            cost -= kx[left];
            left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }


    //优化后的代码
    int equalSubstring2(string s, string t, int maxCost) {
        int ans=0,left=0;
        int curCost=0;
        int n=s.size();
        
        for(int right = 0;right<n;right++){
            curCost += abs(s[right]-t[right]);

            while(curCost>maxCost){
                curCost -=abs(s[left]-t[left]);
                left++;
            }
            ans = max(ans,right-left+1);//答案应该是长度（右边界减去左边界加一）

        }

        return ans;//返回答案
    }    

};

int main() {
    Solution sol;
    // 测试用例
    // auto result = sol.functionName(...);
    // cout << result << endl;
    return 0;
}

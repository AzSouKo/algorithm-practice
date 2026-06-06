/*
 * LeetCode #76.最小覆盖子串
 * 难度：困难
 * 标签：滑动窗口 / 数组 / 哈希表
 * 日期：2026-6-6
 * 思路：使用滑动窗口技术，通过维护一个哈希表来记录目标字符的出现次数，不断扩展和收缩窗口以找到最小覆盖子串
 * 时间复杂度：O(|s| + |t|)
 * 空间复杂度：O(|t|)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool is_covered(int cnt_s[], int cnt_t[]) {
        for (int i = 0; i < 128; i++) {
            if (cnt_s[i] < cnt_t[i]) {
                return false;
            }
        }
        return true;//这是一个辅助函数，用于检查当前窗口内的字符计数是否满足目标字符串 t 的要求。它通过比较两个计数数组 cnt_s 和 cnt_t 来判断是否所有目标字符都被覆盖了。如果 cnt_s 中的某个字符的计数小于 cnt_t 中对应字符的计数，说明当前窗口不满足条件，函数返回 false；如果所有字符都满足条件，则返回 true。这种设计使得主函数中的逻辑更加清晰和简洁。
    }

public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();

        int cnt_t[128] = {0}, cnt_s[128] = {0};

        for (char c : t) {
            cnt_t[c]++;
        }

        int ansl =-1, ansr = n;
        int left = 0;
        for (int right = 0; right < n; right++) {
            cnt_s[s[right]]++;
            while (is_covered(cnt_s, cnt_t)) {
                if (ansl == -1 || right - left + 1 < ansr - ansl + 1) {
                    ansl = left;
                    ansr = right;//如果直接用substr会内存超额，因为每次更新答案都要创建一个新的字符串对象，改为记录左右边界索引，最后再一次性创建结果字符串
                    //所以在更新答案时，直接记录当前窗口的左右边界索引，而不是创建一个新的字符串对象，这样可以避免频繁的内存分配和复制操作，从而提高效率并避免内存超额的问题
                }
                cnt_s[s[left]]--;
                left++;
            }
        }
        return ansl == -1 ? "" : s.substr(ansl, ansr - ansl + 1);

        /*
废弃实时ans = s.substr(...)：原来每次找到合法窗口就生成新字符串，海量临时字符串占满内存；
用ansL、ansR存最短区间下标：全程只存两个 int 整数，内存 O (1)；
最终只调用 1 次 substr：程序结束才生成最终答案字符串，彻底解决超长用例内存爆炸。
        */
    }

    //更优化的写法，省时间省空间
    string minWindow2(string s, string t) {
        int cnt[128]{};
        int kind = 0; // t中不同字符总数
        // 预处理t
        for(char c : t){
            if(cnt[c]++ == 0) kind++;
        }

        int valid = 0; // 窗口达标字符种类
        int l = 0, ansL = -1, minLen = INT_MAX;
        int n = s.size();

        for(int r = 0; r < n; r++){
            char rc = s[r];
            cnt[rc]--; // 进窗口，消耗需求
            // 该字符刚好满足需求 → 达标种类+1
            if(cnt[rc] == 0) valid++;

            // 全部满足，收缩左边界
            while(valid == kind){
                // 更新最优区间
                int curLen = r - l + 1;
                if(curLen < minLen){
                    minLen = curLen;
                    ansL = l;
                }
                char lc = s[l];
                // 移出左字符，归还需求
                if(cnt[lc] == 0) valid--; // 该字符不再达标
                cnt[lc]++;
                l++;
            }
        }
        return ansL == -1 ? "" : s.substr(ansL, minLen);
    }

    //灵神优化版，简洁高效
    string minWindow3(string s, string t) {
        int diff[128]{}; // 窗口每种字母个数 - t 每种字母个数
        int kinds = 0;
        for (char c : t) {
            if (diff[c] == 0) {
                kinds++; // 统计 t 有多少个不同的字母
            }
            diff[c]--;
        }

        int m = s.size();
        int ans_left = -1, ans_right = m;
        int ge_cnt = 0; // 窗口内有 ge_cnt 种字母的出现次数 >= t 中相应字母的出现次数
        int left = 0;

        for (int right = 0; right < m; right++) { // 移动子串右端点
            char c = s[right]; // 右端点字母
            diff[c]++; // 右端点字母移入子串
            if (diff[c] == 0) { // 原来窗口内 c 的出现次数比 t 的少，现在一样多
                ge_cnt++; // 从 < 变成 >=
            }

            while (ge_cnt == kinds) { // 涵盖：所有字母的出现次数都是 >=
                if (right - left < ans_right - ans_left) { // 找到更短的子串
                    ans_left = left; // 记录此时的左右端点
                    ans_right = right;
                }

                char x = s[left]; // 左端点字母
                if (diff[x] == 0) {
                    // x 移出窗口之前，检查出现次数，
                    // 如果窗口内 x 的出现次数和 t 一样，
                    // 那么 x 移出窗口后，窗口内 x 的出现次数比 t 的少
                    ge_cnt--; // 从 >= 变成 <
                }
                diff[x]--; // 左端点字母移出子串
                left++;
            }
        }

        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};




int main() {
    Solution sol;
    
    return 0;
}

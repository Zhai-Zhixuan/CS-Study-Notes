//https://leetcode.cn/problems/distinct-subsequences-ii/description/
//给定一个字符串 s，计算 s 的 不同非空子序列 的个数。
//因为结果可能很大，所以返回答案需要对 10^9 + 7 取余 。
//字符串的 子序列 是经由原字符串删除一些（也可能不删除）字符但不改变剩余字符相对位置的一个新字符串。
//例如，"ace" 是 "abcde" 的一个子序列，但 "aec" 不是。
class Solution {
public:
    int distinctSubseqII(string s) {
        int all=1,new_add;
        int mod=1000000007;
        vector<int>dp(26);
        int l=s.length();
        for(char x:s){
            new_add = (all-dp[x-'a']+mod)%mod;
            dp[x-'a']=(dp[x-'a']+new_add)%mod;
            all=(all+new_add)%mod;
        }
        return (all-1+mod)%mod;
    }
};

//https://leetcode.cn/problems/distinct-subsequences-ii
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

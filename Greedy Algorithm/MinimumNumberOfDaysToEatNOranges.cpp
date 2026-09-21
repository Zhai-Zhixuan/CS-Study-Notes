//https://leetcode.cn/problems/minimum-number-of-days-to-eat-n-oranges/description/
class Solution {
public:
    unordered_map<int,int>dp;
    int minDays(int n) {
        if(n<=1){
            return n;
        }
        if(dp.count(n)){
            return dp[n];
        }
        //n%2:为了使n被2整数所需的天数 +1：吃掉一半橘子花费一天
        int ans =  min(n%2+1+minDays(n/2),n%3+1+minDays(n/3));
        dp[n]=ans;
        return ans;
    }
};

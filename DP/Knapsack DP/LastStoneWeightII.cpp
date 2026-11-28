//https://leetcode.cn/problems/last-stone-weight-ii/description/
class Solution {
public:
    int compute(int t,vector<int>& nums){
        //dp[i][j]=max(dp[i-1][j],dp[i-1][j-nums[i]]+nums[i])
        vector<int>dp(t+1);
        for(int num:nums){
            for(int j=t;j>=num;j--){
                dp[j]=max(dp[j],dp[j-num]+num);
            }
        }
        return dp[t];
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int stone:stones){
            sum+=stone;
        }
        int near=compute(sum/2,stones);
        return sum-2*near;
    }
};

//https://leetcode.cn/problems/target-sum/description/
class Solution {
public:
    int backpack(int y,vector<int>& nums){
        if(y<0){
            return 0;
        }
        vector<int>dp(y+1);
        dp[0]=1;
        for(int num:nums){
            for(int j=y;j>=num;j--){
                dp[j]+=dp[j-num];
            }
        }
        return dp[y];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(sum<target||(sum&1)^(target&1)==1){ //奇偶性保持不变
            return 0;
        }
        int a=(target+sum)/2;
        int n=nums.size();
        int ans=backpack(a,nums);
        return ans;
    }
};

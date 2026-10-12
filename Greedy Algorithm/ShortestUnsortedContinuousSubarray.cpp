//https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/description/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN;
        int right=-1;
        for(int i=0;i<n;i++){
            if(mx>nums[i]){
                right=i;
            }
            else{
                mx=nums[i];
            }
        }
        int left=n;
        int mn=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(mn<nums[i]){
                left=i;
            }
            else{
                mn=nums[i];
            }
        }
        return max(0,right-left+1);
    }
};

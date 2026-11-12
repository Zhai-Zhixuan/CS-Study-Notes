//https://leetcode.cn/problems/super-washing-machines/description/
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size();
        int sum=0,leftsum=0;
        for(int i=0;i<n;i++){
            sum+=machines[i];
        }
        if(sum%n!=0){
            return -1;
        }
        int avg=sum/n;
        int ans=0;
        int finalans=0;
        for(int i=0;i<n;leftsum+=machines[i],i++){
            int leftneed=avg*i-leftsum;
            int rightneed=avg*(n-i-1)-(sum-leftsum-machines[i]);
            if(leftneed>0&&rightneed>0){
                ans=leftneed+rightneed;
            }else{
                ans=max(leftneed,rightneed);
            }
            finalans=max(ans,finalans);
        }
        return finalans;
    }
};

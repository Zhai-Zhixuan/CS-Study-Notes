//https://leetcode.cn/problems/jump-game-ii/description/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int cur=0; // 当前步以内，最右到哪
        int next=0; // 如果再一步，最远到哪
        for(int i=0;i<n;i++){
            if(cur<i){  
                ans++;
                cur=next;
            }
            next=max(next,i+nums[i]);
        }
        return ans;
    }
};

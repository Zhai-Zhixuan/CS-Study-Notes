//https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks/description/
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]-a[1]>b[0]-b[1];
        });
        int n=tasks.size();
        int ans=tasks[0][1];
        for(int i=1;i<n;i++){
            ans=max(ans+tasks[i][0],tasks[i][1]);
        }
        return ans;
    }
};

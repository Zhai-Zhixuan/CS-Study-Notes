//https://leetcode.cn/problems/two-city-scheduling/description/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int>diff;
        int n=costs.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=costs[i][0]; //假设所有人都去a
            diff.push_back(costs[i][1]-costs[i][0]);
        }
        sort(diff.begin(),diff.end()); //计算飞去b的差值并排序
        for(int i=0;i<n/2;i++){
            sum+=diff[i];
        }
        return sum;
    }
};

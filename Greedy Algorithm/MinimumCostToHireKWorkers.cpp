//https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/description/
class Solution {
public:
    struct Employee{
        double ratio;
        int quality;
    };
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<Employee>employees(n);
        for(int i=0;i<n;i++){
            employees[i]={
                (double)wage[i]/quality[i],
                quality[i]
            };
        }
        sort(employees.begin(),employees.end(),[](const Employee& a,const Employee& b){
            return a.ratio<b.ratio;
        });
        priority_queue<int>heap;
        int sum=0;
        double ans=DBL_MAX;
        for(int i=0;i<n;i++){
            int curQuality=employees[i].quality;
            if(heap.size()<k){
                heap.push(curQuality);
                sum+=curQuality;
            }
            else if(heap.top()>curQuality){
                sum-=heap.top();
                heap.pop();
                heap.push(curQuality);
                sum+=curQuality;
            }
            if(heap.size()==k){
                double cost=sum*employees[i].ratio;
                ans=min(ans,cost);
            }
        }
        return ans;
    }
};

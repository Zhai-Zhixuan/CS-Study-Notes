//https://leetcode.cn/problems/maximum-average-pass-ratio/description/
class Solution {
public:
    struct cmp{
        bool operator()(const array<double,3>&a,const array<double,3>&b){
            return a[2]<b[2];
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        int c[n];
        priority_queue<array<double,3>,vector<array<double,3>>,cmp>heap;
        for(int i=0;i<n;i++){
            double a=classes[i][0];
            double b=classes[i][1];
            double d=(a+1.0)/(b+1.0)-a/b;
            heap.push({a,b,d});

        }
        while(extraStudents--){
            auto cur=heap.top();
            heap.pop();
            double a=cur[0]+1;
            double b=cur[1]+1;
            double d=(a+1.0)/(b+1.0)-a/b;
            heap.push({a,b,d});
        }
        double ans=0;
        while(!heap.empty()){
            auto cur=heap.top();
            heap.pop();
            ans+=cur[0]/cur[1];
        }
        return ans/n;
    }
};

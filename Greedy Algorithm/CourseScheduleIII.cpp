//https://leetcode.cn/problems/course-schedule-iii/
class Solution {
public:
    priority_queue<int>heap;
    static bool cmp(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        int time=0;
        int n=courses.size();
        for(int i=0;i<n;i++){
            int d=courses[i][0];
            int l=courses[i][1];
            if(time+d<=l){
                time+=d;
                heap.push(d);
            }
            else{
                if(!heap.empty()&&heap.top()>d){
                    time+=d-heap.top();
                    heap.pop();
                    heap.push(d);
                }
            }
        }
        return heap.size();
    }
};

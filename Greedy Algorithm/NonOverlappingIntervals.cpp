//https://leetcode.cn/problems/non-overlapping-intervals/description/
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt=0,cur=-60000;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<cur){
                cnt++;
            }
            else{
                cur=intervals[i][1];
            }
        }
        return cnt;
    }
};

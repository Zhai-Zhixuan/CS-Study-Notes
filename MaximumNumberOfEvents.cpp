//https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/description/
class Solution {
public:
    priority_queue<int,vector<int>,greater<int>>heap;
    static int cmp(const vector<int>&a,const vector<int>&b){
        return a[0]<b[0];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),cmp);
        int min=events[0][0];
        int maxm=events[0][1];
        int n=events.size();
        for(int i=0;i<n;i++){
            maxm=max(maxm,events[i][1]);
        }
        int ans=0,i=0;
        for(int day=min;day<=maxm;day++){
            while(i<n&&events[i][0]==day){
                heap.push(events[i++][1]);
            }
            while(!heap.empty()&&heap.top()<day){
                heap.pop();
            }
            if(!heap.empty()){
                heap.pop();
                ans++;
            }
        }
        return ans;
    }
};

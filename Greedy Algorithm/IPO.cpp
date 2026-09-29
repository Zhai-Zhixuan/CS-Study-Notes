//https://leetcode.cn/problems/ipo/description/
class Solution {
public:
    priority_queue<int>heap;
    struct Project{
        int profits;
        int capital;
    };
    vector<Project>projects;
    static int cmp(const Project&a,const Project&b){
        return a.capital<b.capital;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        for(int i=0;i<n;i++){
            projects.push_back({profits[i],capital[i]});
        }
        sort(projects.begin(),projects.end(),cmp);
        int i=0;
        while(k>0){
            while(i<n&&projects[i].capital<=w){
                heap.push(projects[i++].profits);
            }
            if(heap.empty()){
                break;
            }
            w+=heap.top();
            heap.pop();
            k--;
        }
        return w;
    }
};

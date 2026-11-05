//https://leetcode.cn/problems/minimum-number-of-refueling-stops/
//反悔贪心，当汽车油不够继续前进时，就从之前经过的加油站中，选择油量最多的一个加油
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>heap;
        int cnt=0;
        int to=startFuel;
        if(to>=target){
            return cnt;
        }
        for(vector<int>station:stations){
            int position=station[0],fuel=station[1];
            while(to<position&&!heap.empty()){
                to+=heap.top();
                heap.pop();
                cnt++;
            }
            if(to<position){
                return -1;
            }
            heap.push(fuel);
        }
        while(to<target&&!heap.empty()){
            to+=heap.top();
            heap.pop();
            cnt++;
        }
        return to>=target?cnt:-1;
    }
};

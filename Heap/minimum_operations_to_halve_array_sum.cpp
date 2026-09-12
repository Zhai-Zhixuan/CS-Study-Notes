//https://leetcode.cn/problems/minimum-operations-to-halve-array-sum
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>heap;
        double sum=0;
        for(int num:nums){
            heap.push((double)num);
            sum+=num;
        }
        sum/=2;
        int ans=0;
        for(double minus=0,cur;minus<sum;ans++,minus+=cur){
            cur=heap.top()/2;
            heap.pop();
            heap.push(cur);
        }
        return ans;
    }
};

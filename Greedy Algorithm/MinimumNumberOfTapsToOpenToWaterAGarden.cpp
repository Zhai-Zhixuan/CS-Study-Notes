//https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>right(n+1);
        // right[i] = j
        // 所有左边界在i的水龙头里，最右影响到的位置在j
        for(int i=0;i<=n;i++){
            int start=max(0,i-ranges[i]);
            right[start]=max(right[start],i+ranges[i]);
        }
        int ans=0;
        int cur=0,next=0;
        for(int i=0;i<n;i++){
            next=max(next,right[i]);
            if(cur==i){ //最远到达右边界==>打开新水龙头
                if(next>i){
                    ans++;
                    cur=next;
                }
                else{
                    return -1;
                }
            }
        }
        return ans;
    }
};

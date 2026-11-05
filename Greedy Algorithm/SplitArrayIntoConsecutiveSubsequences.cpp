//https://leetcode.cn/problems/split-array-into-consecutive-subsequences/description/
class Solution {
public:
    bool isPossible(vector<int>& nums){
        //尽可能延长已经存在的子序列。
        //如果无法延长，再考虑创建一个新的子序列。
        unordered_map<int,int>cnt; //统计每个num出现次数
        unordered_map<int,int>end; //统计以num结尾的次数
        for(int num:nums){
            cnt[num]++;
        }
        for(int num:nums){
            if(cnt[num]==0){
                continue;
            }
            cnt[num]--; //延长已有序列，还是创建新序列，当前的 num 都会被使用
            if(end[num-1]>0){
                end[num-1]--;
                end[num]++;
            }
            else if(cnt[num+1]>0&&cnt[num+2]>0){
                cnt[num+1]--;
                cnt[num+2]--;
                end[num+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

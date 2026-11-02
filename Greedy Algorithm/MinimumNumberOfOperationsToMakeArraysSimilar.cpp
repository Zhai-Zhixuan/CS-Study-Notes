//https://leetcode.cn/problems/minimum-number-of-operations-to-make-arrays-similar/description/
class Solution {
public:
    int split(vector<int>& nums,int n){
        //前面是奇数，后面是偶数
        int ans=0;
        for(int i=0;i<n;i++){
            if((nums[i]&1)==1){
                std::swap(nums[i],nums[ans++]);
            }
        }
        return ans;
    }
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        // +2 / -2 不改变奇偶性
        int n=nums.size();
        int oddSize=split(nums,n);
        split(target,n);
        sort(nums.begin(),nums.begin()+oddSize);
        sort(nums.begin()+oddSize,nums.end());
        sort(target.begin(),target.begin()+oddSize);
        sort(target.begin()+oddSize,target.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(target[i]-nums[i]);
        }
        ans/=4;
        return ans;
    }
};

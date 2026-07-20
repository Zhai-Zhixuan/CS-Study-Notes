//https://leetcode.cn/problems/sort-array-by-parity-ii
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int l=nums.size();
        for(int odd=1,even=0,i=l-1;odd<=i&&even<=i;){
            if(nums[i]&1==1){ //nums[i]为奇数时
                swap(nums[odd],nums[i]);
                odd+=2;
            }
            else{
                swap(nums[even],nums[i]);
                even+=2;
            }
        }
        return nums;
    }
};

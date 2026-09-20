//给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
//注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
//https://leetcode.cn/problems/largest-number/description/
class Solution {
public:
    static bool cmp(string a,string b){
        return a+b>b+a;
    }
    string way2(vector<int>& nums){
        vector<string>strs;
        for(int s:nums){
            strs.push_back(to_string(s));
        }
        sort(strs.begin(),strs.end(),cmp);
        if(strs[0]=="0"){
            return "0";
        }
        string ans;
        for(string n:strs){
            ans+=n;
        }
        return ans;
    }
    string largestNumber(vector<int>& nums) {
        return way2(nums);
    }
};

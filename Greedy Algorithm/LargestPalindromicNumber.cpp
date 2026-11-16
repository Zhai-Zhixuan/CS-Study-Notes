//https://leetcode.cn/problems/largest-palindromic-number/description/
class Solution {
public:
    string largestPalindromic(string num) {
        int n=num.size();
        vector<int>cnt(10);
        for(int i=0;i<n;i++){
            cnt[num[i]-'0']++;
        }
        int mid=-1;
        for(int i=9;i>0;i--){
            if((cnt[i]&1)==1){
                mid=i;
                break;
            }
        }
        string arr;
        int len=0;
        for(int i=9;i>0;i--){
            for(int j=0;j<cnt[i]/2;j++){
                arr.push_back('0'+i);
                len++;
            }
        }
        int leftSize=len;
        for(int i=0;i<cnt[0]/2;i++){
            arr.push_back('0');
            len++;
        }
        if(mid==-1&&cnt[0]%2==1){
            mid=0;
        }
        if(leftSize==0){
            if(mid!=-1){
                return to_string(mid);
            }
            else{
                return "0";
            }
        }
        else if(mid!=-1){
            arr.push_back('0'+mid);
        }
        for(int i=len-1;i>=0;i--){
            arr.push_back(arr[i]);
        }
        return arr;
    }
};

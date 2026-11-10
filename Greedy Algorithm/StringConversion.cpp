//https://www.lintcode.com/problem/3869
class Solution {
public:
   
    bool canConvert(string &str1, string &str2) {
        vector<int>mp(26);
        int n=str1.size();
        if(str1==str2){
            return true;
        }
        int kinds=0;
        for(int i=0;i<n;i++){
            if(mp[str2[i]-'a']++==0){ //mp[i]:i字符在str2出现的次数
                kinds++;
            }
        }
        if(kinds==26){
            return false;
        }
        fill(mp.begin(),mp.end(),-1); //mp[i]:字符i上一次在 str1 中出现的位置
        for(int i=0;i<n;i++){
            int cur=str1[i]-'a';
            if(mp[cur]!=-1&&str2[mp[cur]]!=str2[i]){
                return false;
            }
            mp[cur]=i;
        }
        return true;
    }
};

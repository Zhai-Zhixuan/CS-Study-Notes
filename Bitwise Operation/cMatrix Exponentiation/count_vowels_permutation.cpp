//https://leetcode.cn/problems/count-vowels-permutation
class Solution {
public:
    const int mod = 1000000007;
    vector<vector<int>>multiply(const vector<vector<int>>&a,const vector<vector<int>>&b){
        int m=a.size();
        int n=b[0].size();
        int c=a[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<c;k++){
                    ans[i][j]=int(((long long)a[i][k]*b[k][j]+ans[i][j])%mod);
                }
            }
        }
        return ans;
    }
    vector<vector<int>>power(vector<vector<int>>a,int b){
        int n=a.size();
        vector<vector<int>>ans(n,vector<int>(n));
        for(int i=0;i<n;i++){
            ans[i][i]=1;
        }
        for(;b>0;b>>=1){
            if(b&1){
                ans=multiply(ans,a);
            }
            a=multiply(a,a);
        }
        return ans;
    }
    int countVowelPermutation(int n) {
        //dp[i][j]:长度为i,且以j字符结尾的合法字符串数量
        vector<vector<int>>start={{1,1,1,1,1}};
        vector<vector<int>>base={{0,1,0,0,0},{1,0,1,0,0},{1,1,0,1,1},{0,0,1,0,1},{1,0,0,0,0}};
        vector<vector<int>>ans=multiply(start,power(base,n-1));
        int ret=0;
        for(int a:ans[0]){
            ret=(ret+a)%mod;
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int> > dp = vector<vector<int>>(201,vector<int>(201));
    int f(int n,int m,vector<vector<int>>& matrix){
        int length=0;
        if(dp[n][m]!=0){
            return dp[n][m];
        }
        if(n>0&&matrix[n-1][m]>matrix[n][m]){
            length=max(length,f(n-1,m,matrix));
        }
        if(n+1<matrix.size()&&matrix[n+1][m]>matrix[n][m]){
            length=max(length,f(n+1,m,matrix));
        }
        if(m>0&&matrix[n][m-1]>matrix[n][m]){
            length=max(length,f(n,m-1,matrix));
        }
        if(m+1<matrix[0].size()&&matrix[n][m+1]>matrix[n][m]){
            length=max(length,f(n,m+1,matrix));
        }
        dp[n][m]=length+1;
        return length+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,f(i,j,matrix));
            }
        }
        return ans;
    }
};

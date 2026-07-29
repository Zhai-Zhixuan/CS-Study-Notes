//https://leetcode.cn/problems/student-attendance-record-ii
//可以用字符串表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：
//'A'：Absent，缺勤
//'L'：Late，迟到
//'P'：Present，到场
//如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：
//按 总出勤 计，学生缺勤（'A'）严格 少于两天。
//学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
//给你一个整数 n ，表示出勤记录的长度（次数）。请你返回记录长度为 n 时，可能获得出勤奖励的记录情况 数量 。答案可能很大，所以返回对 109 + 7 取余 的结果。
class Solution {
public:
    const int mod=1000000007;
    vector<vector<int>>multiply(const vector<vector<int>>&a,const vector<vector<int>>&b){
        int n=a.size();
        int m=b[0].size();
        int c=a[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<c;k++){
                    ans[i][j]=(int)(((long long)a[i][k]*b[k][j]+ans[i][j])%mod);
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
    int checkRecord(int n) {
        //dp[i][a][b]:前i天中，有a天缺勤，且最后正好有b天连续迟到的情况下所有可能的合法记录数量(a<=1,b<=2)
        //dp[i][0][0]->dp[i][0]->0缺，0迟 == dp[i-1][0、1、2]
        //dp[i][0][1]->dp[i][1]->0缺，1迟
        //dp[i][0][2]->dp[i][2]->0缺，2迟
        //dp[i][1][0]->dp[i][3]->1缺，0迟 == dp[i-1][0、1、2、3、4、5]
        //......
        //[i][a][b]->[i][3*a+b] 三维->二维
        vector<vector<int>>start={{1,1,0,1,0,0}}; //1天
        vector<vector<int>>base={{1,1,0,1,0,0},{1,0,1,1,0,0},{1,0,0,1,0,0},{0,0,0,1,1,0},{0,0,0,1,0,1},{0,0,0,1,0,0}};
        vector<vector<int>>ans=multiply(start,power(base,n-1));
        int ret=0;
        for(int i=0;i<6;i++){
            ret=(ret+ans[0][i])%mod;
        }
        return ret;
    }
};

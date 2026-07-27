class Solution {
public:
    vector<vector<int>> multiply(const vector<vector<int>>&a,const vector<vector<int>>&b){ //矩阵乘法
        int n = a.size();
        int m = b[0].size();
        int t=a[0].size();
        vector<vector<int>>k(n,vector<int>(m));
        for(int i = 0;i < n;i++){ //遍历a行
            for(int j = 0;j < m;j++){ //遍历b列
                for(int x=0;x<t;x++){ //遍历a列==b行
                    k[i][j]+=a[i][x]*b[x][j];
                }
            }
        }
        return k;
    }
    vector<vector<int>> power(vector<vector<int>>a,int b){ //求矩阵快速幂
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
    int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        vector<vector<int>>start = {{1,0}};
        vector<vector<int>>base = {{1,1},{1,0}};
        //F(n) = F(n-1) + F(n-2)
        //F(n-1) F(n-2)  1 1
        //               1 0
        //               F(n) F(n-1)
        vector<vector<int>>ans = multiply(start,power(base,n-1));
        return ans[0][0];
    }
};

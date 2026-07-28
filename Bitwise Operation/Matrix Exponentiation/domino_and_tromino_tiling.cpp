//有两种形状的瓷砖：一种是 2 x 1 的多米诺形，另一种是形如 "L" 的托米诺形。两种形状都可以旋转。
//给定整数 n ，返回可以平铺 2 x n 的面板的方法的数量。返回对 109 + 7 取模 的值。
//平铺指的是每个正方形都必须有瓷砖覆盖。两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，使得恰好有一个平铺有一个瓷砖占据两个正方形。
class Solution {
public:
    int f(int n, int k) { //打表找规律
        if (n == 0) {
            return k == 0 ? 1 : 0;
        }
        if (n == 1) {
            return 1;
        }
        if (k == 1) {
            return f(n - 1, 0) + f(n - 1, 1);
        } else {
            return f(n - 2, 0) + f(n - 1, 0) + f(n - 2, 1) * 2;
        }
    }
    int numTilings(int n) {
        for (int i = 1; i <= 9; i++) {
            cout << "铺满2*" << i << "的区域方法数:" << f(i, 0) << "\n";
        }
        return 0;
    }
};


class Solution {
    //f(n)=f(n-1)*2+f(n-3)
public:
    const long long mod=1000000007;
    vector<vector<long long>>multiply(const vector<vector<long long>>&a,const vector<vector<long long>>&b) {
        int m=a.size();
        int n=b[0].size();
        int c=a[0].size();
        vector<vector<long long>>ans(m,vector<long long>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<c;k++){
                    ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%mod;
                }
            }
        }
        return ans;
    }
    vector<vector<long long>>power(vector<vector<long long>>a,int b){
        int n=a.size();
        vector<vector<long long>>ans(n,vector<long long>(n));
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
    int numTilings(int n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        vector<vector<long long>>start={{2,1,1}};
        vector<vector<long long>>base={{2,1,0},{0,0,1},{1,0,0}};
        vector<vector<long long>>ans=multiply(start,power(base,n-2));
        return ans[0][0];
    }
};

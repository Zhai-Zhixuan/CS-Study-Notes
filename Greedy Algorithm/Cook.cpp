//https://www.luogu.com.cn/problem/P1417
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Food{
    int a;
    int b;
    int c;
};
int main(){
    int t,n;
    cin >> t >> n;
    vector<Food>foods(n);
    for(int i=0;i<n;i++){
        cin >> foods[i].a;
    }
    for(int i=0;i<n;i++){
        cin >> foods[i].b;
    }
    for(int i=0;i<n;i++){
        cin >> foods[i].c;
    }
    sort(foods.begin(),foods.end(),[](Food &x,Food &y){
        return 1LL*x.c*y.b<1LL*x.b*y.c;
    });
    vector<vector<long long>>dp(n+1,vector<long long>(t+1,-1)); 
    //dp[i][j]:前i种食材在j时间的美味指数
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=t;j++){
            dp[i][j]=dp[i-1][j]; //不选当前食材
            int p=j-foods[i-1].c;
            if(p>=0&&dp[i-1][p]!=-1){
                dp[i][j]=max(dp[i][j],dp[i-1][p]+foods[i-1].a-1LL*j*foods[i-1].b);
            }
        }
    }
    long long ans=0;
    for(int i=0;i<=t;i++){
        ans=max(ans,dp[n][i]);
    }
    cout << ans << endl;
}

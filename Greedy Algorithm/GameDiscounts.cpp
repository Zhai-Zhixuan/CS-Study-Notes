//https://leetcode.cn/problems/tJau2o/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int well=0;
int m=0;
const int MAXN=500;
vector<int>cost(MAXN);
vector<long long>val(MAXN);
long long compute(){
    vector<long long>dp(well+1);
    for(int i=0;i<m;i++){
        for(int j=well;j>=cost[i];j--){
            dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
        }
    }
    return dp[well];
}
int main(){
    int n,x;
    cin >> n >> x;
    well=x;
    int l=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        int a,b;
        long long w;
        cin >> a >> b >> w;
        int benefit=a-2*b;
        if(benefit>=0){
            ans+=w;
            well+=benefit;
        }
        else{
            cost[m]=-benefit;
            val[m++]=w;
        }
    }
    ans+=compute();
    cout << ans << endl;
    return 0;
}

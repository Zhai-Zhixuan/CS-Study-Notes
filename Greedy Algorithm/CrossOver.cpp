//https://www.luogu.com.cn/problem/P1809
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>dp(100005);
vector<int>times(100005);
int f(int n){
    //ai+a0+a(i-1)+a0
    //a1+a0+ai+a1
    if(n>=1) dp[0]=times[0];
    if(n>=2) dp[1]=times[1];
    if(n>=3) dp[2]=times[1]+times[0]+times[2];
    for(int i=3;i<n;i++){
        dp[i]=min(dp[i-1]+times[i]+times[0],dp[i-2]+times[0]+times[1]*2+times[i]);
    }
    return dp[n-1];
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> times[i];
    }
    sort(times.begin(),times.begin()+n);
    cout << f(n) << endl;
}

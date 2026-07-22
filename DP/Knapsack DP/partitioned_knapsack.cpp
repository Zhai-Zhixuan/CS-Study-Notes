//https://www.nowcoder.com/share/jump/1997206311784716845335
#include <array>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>>dp(2001, vector<int>(2001));
//dp[i][j]:1--i组不超过容量j的情况下的最大价值
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>arr(n+1, vector<int>(3));
    int teams = 1;
    arr[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        long long w, v;
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    sort(arr.begin() + 1, arr.end(), [](const vector<int>& a,
    const vector<int>& b) {
        return a[2] < b[2];
    });
    for(int i=2;i<=n;i++){
        if (arr[i][2] != arr[i - 1][2]) { //统计组数量=>相邻两组编号不同
            teams++;
        }
    }
    //cout << teams << " ";
    for (int i = 1, start = 1, end = 2; start <= n; i++) { //遍历组
        while (end <= n &&
                arr[end][2] == arr[start][2]) { //当前物品等于起始物品组号
            end++;
        }
        for (int j = 0; j <= m; j++) { //遍历背包容量
            dp[i][j] = dp[i - 1][j]; //不选i组任何物品
            for (int k = start; k < end; k++) { //遍历组内物品
                if (j >= arr[k][0]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[k][0]] + arr[k][1]);
                }
            }
        }
        start = end++;
    }
    cout << dp[teams][m];
}


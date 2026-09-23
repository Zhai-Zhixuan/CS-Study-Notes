// 分成k份的最大乘积
// 一个数字n一定要分成k份，得到的乘积尽量大是多少
// 数字n和k，可能非常大，到达10^12规模
// 结果可能更大，所以返回结果对 1000000007 取模
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int mod=1000000007;
long long power(long long x,long long y) {
    long long res = 1;
    while (y) {
        if (y & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}
int f1(int n,int k) {
    int x = n / k;
	int y = n % k;
    int part1 = power(x+1,y);
	int part2 = power(x,k-y);
    return (long long)part1 * part2 % mod;
}
int f2(int n, int k) {
	if (k == 1)   return n;
	int ans = 0;
    for (int i = 1; i <= n && n-i>=k-1;i++) {
        ans = max(ans, i*f2(n - i, k-1));
    }
    return ans;
}
int main(){
	int times = 1000;
	cout << "test begin" << endl;
    for (int i = 0; i < times; i++) {
		int n = rand() % 15 + 1;
		int k = rand() % n + 1;
		long long ans1 = f1(n, k);
		long long ans2 = f2(n, k);
        if (ans1 != ans2) {
           cout << "error!";
		   cout << "nums: ";
		    cout << endl;
			cout << "ans1: " << ans1 << endl;
			cout << "ans2: " << ans2 << endl;
          }
        }
		cout << "test end" << endl;
    }

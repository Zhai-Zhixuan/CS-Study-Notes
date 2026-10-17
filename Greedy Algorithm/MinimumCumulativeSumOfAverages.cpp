// 平均值最小累加和
// 给定一个数组arr，长度为n
// 再给定一个数字k，表示一定要将arr划分成k个集合
// 每个数字只能进一个集合
// 返回每个集合的平均值都累加起来的最小值
// 平均值向下取整
// 1 <= n <= 10^5
// 0 <= arr[i] <= 10^5
// 1 <= k <= n
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
const long long INF = 1e18;
long long f1(vector<int> arr, int k) {
	int n = arr.size();
	sort(arr.begin(), arr.end());
	long long sum = 0, sum2 = 0;
	for (int i = 0; i < k-1; i++) {
		sum += arr[i];
	}
	for(int i=k-1;i<n;i++){
		sum2 += arr[i];
	}
	sum += sum2 / (n - k + 1);
	return sum;
}
long long process(vector<int>& arr, int k, int i, vector<long long>& sum,vector<int>& cnt) {
	int n = arr.size();
	if (i == n) {
		long long ans = 0;
		for(int i=0;i<k;i++){
			if(cnt[i]==0){
				return INF;
			}
			ans += sum[i] / cnt[i];
		}
		return ans;
	}
	long long ans = INF;
	for(int j=0;j<k;j++){
		sum[j] += arr[i];
		cnt[j]++;
		ans = min(ans, process(arr, k, i+1, sum,cnt));
		sum[j] -= arr[i];
		cnt[j]--;
	}
	return ans;
}
long long f2(int k,vector<int>arr,int i) {
	vector<long long>sum(k);
	vector<int>cnt(k);
	return process(arr, k, i, sum,cnt);
}
vector<int> randomArray(int n,int v) {
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		arr[i] = rand() % v;
	}
	return arr;
}
int main(){
	srand(time(nullptr));
	int times = 1000;
	cout << "测试开始" << endl;
	for (int i = 0; i < times; i++) {
		int n = rand() % 8 + 1;
		vector<int>arr = randomArray(n, 100);
		int k = rand() % n + 1;
		long long ans1 = f1(arr, k);
		long long ans2 = f2(k,arr, 0);
		if (ans1 != ans2) {
			cout << "Wrong Answer" << endl;
			cout << "k= " << k << endl;
			cout << "arr= ";
			for(int x:arr){
				cout << x << " ";
			}
			cout << "\n贪心答案: " << ans1 << endl;
			cout << "暴力答案: " << ans2 << endl;
			return 0;
		}
	}
	cout << "测试结束" << endl;
}

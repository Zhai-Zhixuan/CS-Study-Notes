#include<iostream>
#include<vector>
using namespace std;
int MAXN = 1001;
vector<vector<int>>dp(MAXN, vector<int>(MAXN));
void build() {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			dp[i][j] = -1;
		}
	}
}
int sg(int a, int b) {
	if (a == 1 && b == 1) {
		return 0;
	}
	if (dp[a][b] != -1) {
		return dp[a][b];
	}
	vector<bool>appear(max(a, b) + 1);
	if (a > 1) {
		for (int l = 1, r = a - 1; l < a; l++, r--) {
			appear[sg(l, r)] = true;
		}
	}
	if (b > 1) {
		for (int l = 1, r = b - 1; l < b; l++, r--) {
			appear[sg(l, r)] = true;
		}
	}
	int ans=0;
	for (int i = 0; i <= max(a, b); i++) {
		if (!appear[i]) {
			ans = i;
			break;
		}
	}
	dp[a][b] = ans;
	return ans;
}
void f1() {
	cout << "石子数9以内所有组合的sg值" << endl;
	cout << "   ";
	for (int i = 1; i <= 9; i++) {
		cout << i << " ";
	}
	cout << "\n\n";
	for (int i = 1; i <= 9; i++) {
		cout << i << "  ";
		for (int j = 1; j < i; j++) {
			cout << "X ";
		}
		for (int j = i; j <= 9; j++) {
			cout << sg(i, j) << " ";
		}
		cout << "\n";
	}
}
void f2() {
	cout << "石子数9以内所有组合的sg值,但是行列都-1" << endl;
	cout << "   ";
	for (int i = 0; i < 9; i++) {
		cout << i << " ";
	}
	cout << "\n\n";
	for (int i = 1; i <= 9; i++) {
		cout << i-1 << "  ";
		for (int j = 1; j < i; j++) {
			cout << "X ";
		}
		for (int j = i; j <= 9; j++) {
			cout << sg(i, j) << " ";
		}
		cout << "\n";
	}
}
int lowZero(int status) {
	int cnt = 0;
	while (status > 0) {
		if ((status & 1) == 0) {
			break;
		}
		status >>= 1;
		cnt++;
	}
	return cnt;
}
void f3() {
	cout << "测试开始" << endl;
	for(int i=1;i<MAXN;i++){
		for(int j=1;j<MAXN;j++){
			int sg1 = sg(i, j);
			int sg2 = lowZero((i-1)|(j-1));
			if (sg1 != sg2) {
				cout << "出错了";
			}
		}
	}
	cout << "测试结束" << endl;
}

int main(){
	build();
	f1();
	f2();
	f3();
}

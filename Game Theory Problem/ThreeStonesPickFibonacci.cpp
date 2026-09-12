#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 201;
int f[] = { 1,2,3,5,8,13,21,34,55,89,144};
int f_len = sizeof(f) / sizeof(f[0]);
int sg[MAXN];
bool appear[MAXN];
void build() {
	for (int i = 1; i < MAXN; i++) {
		fill(appear, appear+MAXN, false);
		for (int j = 0; j < f_len && i - f[j]>=0; j++) {
			appear[sg[i - f[j]]] = true;
		}
		for(int j = 0; j < MAXN; j++) {
			if (!appear[j]) {
				sg[i] = j;
				break;
			}
		}
	}
}
string win(int a, int b, int c) {
	if (sg[a] ^ sg[b] ^ sg[c]) {
		return "先手必胜";
	}
	else {
		return "后手必胜";
	}
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	build();
	cout << win(a, b, c) << endl;
	for(int i=0;i<MAXN;i++){
		cout<<"sg("<<i<<")"<<sg[i] << endl;
	}
	return 0;
}

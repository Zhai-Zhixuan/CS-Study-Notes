//https://www.luogu.com.cn/problem/P2148
#include<iostream>
#include<vector>
using namespace std;
int lowZero(int status){
    int cnt=0;
    while(status>0){
        if((status&1)==0){
            break;
        }
        status>>=1;
        cnt++;
    }
    return cnt;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n;
        int sg=0;
        for(int i=0;i<n;i+=2){
            cin >> a >> b;
            sg^=lowZero((a-1)|(b-1));
        }
        cout << (sg==0?"NO\n":"YES\n");
    }
}

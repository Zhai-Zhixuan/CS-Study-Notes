//https://www.luogu.com.cn/problem/P4279
#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt=0;
        int eor=0;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            cnt+=x;
            eor^=x;
        }
        if(cnt==n){
            cout << (n%2==0?"John\n":"Brother\n");
        }
        else{
            cout << (eor==0?"Brother\n":"John\n");
        }
    }
}

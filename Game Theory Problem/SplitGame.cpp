//https://www.luogu.com.cn/problem/P3185
#include <iostream>
#include <vector>
using namespace std;
int MAXN=21;
int MAXV=101;
vector<bool>appear(MAXV);
vector<int>sg(MAXN);
vector<int>nums(MAXN);
void build(){
    for(int i=1;i<MAXN;i++){
        for(int j=0;j<MAXV;j++){
            appear[j]=false;
        } //fill(appear.begin(),appear.end(),false);
        for(int j=i-1;j>=0;j--){
            for(int k=j;k>=0;k--){
                appear[sg[j]^sg[k]]=true;
            }
        }
        for(int j=0;j<MAXV;j++){
            if(!appear[j]){
                sg[i]=j;
                break;
            }
        }
    }
}
string compute(int n){
    int eor=0; 
    //计算整个游戏的SG值，每颗糖豆看作独立的ICG游戏
    //sg==0，后手赢；sg!=0，先手赢
    for(int i=n-1;i>=0;i--){
        if(nums[i]%2!=0){
            eor^=sg[i];
        }
    }
    if(eor==0){ //特殊情况判断，总SG==0 => 先手必败
        return "-1 -1 -1\n0";
    }
    int cnt=0,a=-1,b=-1,c=-1,pos; //sg后
    for(int i=n-1;i>0;i--){ 
        //先手必胜=>存在一种第一步，使得操作之后的总 SG = 0
        if(nums[i]>0){ //i号瓶有东西
            for(int j=i-1;j>=0;j--){
                for(int k=j;k>=0;k--){
                    // i -> j k
                    pos = eor^sg[i]^sg[j]^sg[k];
                    if(pos==0){ //行动有效
                        cnt++;
                        if(a==-1){ //没设置过行动=>设置（此时字典序最小）
                            a=i;
                            b=j;
                            c=k;
                        }
                    }
                }
            }
        }
    }
    return to_string(n-1-a)+" "+to_string(n-1-b)+" "+to_string(n-1-c)+"\n"+to_string(cnt);
}
int main(){
    build();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=n-1;i>=0;i--){
            cin >> nums[i];
        }
        cout << compute(n) << endl;
    }
}

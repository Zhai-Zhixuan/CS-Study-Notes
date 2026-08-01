//https://www.nowcoder.com/share/jump/1997206311785594945975
#include <iostream>
#include <vector>
using namespace std;
const int maxn=1000001;
vector<int>father(maxn);
vector<int>arrsize(maxn);
vector<int>stack(maxn);
void build(){
    for(int i=0;i<maxn;i++){
        father[i]=i;
        arrsize[i]=1;
    }
}
int find(int i){ //扁平化:路径节点的重要节点改为根节点
    int size=0;
    while(i!=father[i]){
        stack[size++]=i;
        i=father[i];
    }
    while(size>0){ //路径压缩：father[节点] = 根节点，从size-1开始
        father[stack[--size]]=i;
    }
    return i;
}
bool isSameSet(int a,int b){
    return find(a)==find(b);
}
void arrunion(int a,int b){
    int fx=find(a),fy=find(b);
    if(arrsize[fx]>=arrsize[fy]){ //小挂大
        father[fy]=fx;
        arrsize[fx]+=arrsize[fy];
    }
    else{
        father[fx]=fy;
        arrsize[fy]+=arrsize[fx];
    }
}
int main() {
    int m,n;
    cin >> n >> m;
    build();
    while(m--){
        int opt,x,y;
        cin >> opt >> x >> y;

        if(opt==1){
            if(isSameSet(x,y)){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
        else{
            arrunion(x,y);
        }
    }
}

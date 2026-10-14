//https://www.luogu.com.cn/problem/P12331
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//至少准备多少钱->至多花多少钱->大根堆排序 记录花费最多的方案
struct Game{
    int k;
    int b;
    int people=0; //记录当前项目多少人
    long long earn()const{
        return b+k*people+k*(people+1);
        //earn记录增加一个人后的增量 earn=b+k*x+k*(x+1)
    }
};
struct cmp{
    bool operator()(const Game& a,const Game& b)const{
        return a.earn()<b.earn();    //大根堆按earn大小排序
    }
};
priority_queue<Game,vector<Game>,cmp>heap;

long long compute(int n){
    long long money=0;
    int total=0;
    while(total<n&&!heap.empty()){ //挑选大根堆堆顶取出，人数+1后重新放入排序
        if(heap.top().earn()<=0){     
            //当总人数等于n或堆顶earn<=0时结束循环
            break;
        }
        Game x=heap.top();
        money+=x.earn();     //将所有earn求和返回
        heap.pop();
        x.people++;
        heap.push(x);
        total++;
    }
    return money;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        Game x;
        cin >> x.k >> x.b;
        heap.push(x);
    }
    cout <<  compute(n);
}

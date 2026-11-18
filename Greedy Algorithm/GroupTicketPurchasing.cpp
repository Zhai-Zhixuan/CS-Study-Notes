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

/** 取最大收益 → 执行一次操作 → 重新计算收益 → 放回堆
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<array>
using namespace std;
struct cmp{
    bool operator()(const array<long long,4>&a,const array<long long,4>&b)const{
        return a[3]<b[3];
    }
};
long long cost(long long k,long long b,long long people){
    return people*max(k*people+b,0LL);
}
int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<array<long long,4>,vector<array<long long,4>>,cmp>heap;
    for(int i=0;i<m;i++){
        int k,b;
        cin >> k >> b;
        int t=cost(k,b,1)-cost(k,b,0);
        if(t>0) heap.push({k,b,0,t});
    }
    long long ans=0;
    while(n--&&!heap.empty()){
        auto cur=heap.top();
        heap.pop();
        long long k=cur[0];
        long long b=cur[1];
        long long people=cur[2]+1;
        long long earn=cost(k,b,people+1)-cost(k,b,people);
        ans+=cur[3];
        if(earn>0)heap.push({k,b,people,earn});
    }
    cout << ans << endl;
}**/

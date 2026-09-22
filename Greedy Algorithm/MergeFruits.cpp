//https://www.luogu.com.cn/problem/P1090
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x;
    priority_queue<int,vector<int>,greater<int>>heap;
    for(int i=0;i<n;i++){
        cin >> x;
        heap.push(x);
    }
    int cost=0;
    long long sum=0;
    while(heap.size()>1){
        int a=heap.top();
        heap.pop();
        int b=heap.top();
        heap.pop();
        cost=a+b;
        sum+=cost;
        heap.push(cost);
    }
    cout << sum;
}

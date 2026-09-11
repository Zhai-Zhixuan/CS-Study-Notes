//https://www.nowcoder.com/share/jump/1997206311789113191159
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
//任何一个重合区域的左边界，都一定是某一条线段的左边界
vector<vector<int>>line(10005,vector<int>(2));
vector<int>heap(10005);
int sz=0;
void pop(){
    swap(heap[0],heap[--sz]);
    int i=0,l=1;
    while(l<sz){
        int best=(l+1<sz&&heap[l+1]<heap[l])?l+1:l;
        best=heap[best]<heap[i]?best:i;
        if(best==i) break;
        swap(heap[i],heap[best]);
        i=best;
        l=i*2+1;
    }
}
void add(int x){
    heap[sz]=x;
    int i=sz++;
    while(i>0&&heap[i]<heap[(i-1)/2]){
        swap(heap[i],heap[(i-1)/2]);
        i=(i-1)/2;
    }
}
int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) { 
        cin >> line[i][0] >> line[i][1];
    }
    sort(line.begin(),line.begin()+n,[](const vector<int>& a,const vector<int>& b){
        return a[0]<b[0];
    });
    int ans=0;
    for(int i=0;i<n;i++){
        while(sz>0&&heap[0]<=line[i][0]){
            pop();
        }
        add(line[i][1]);
        ans=max(ans,sz);
    }
    cout << ans;
}

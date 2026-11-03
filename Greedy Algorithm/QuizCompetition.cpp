//https://www.nowcoder.com/practice/2a9089ea7e5b474fa8f688eae76bc050
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int n;
vector<vector<int>>nums(200005,vector<int>(2));
int compute(){
    sort(nums.begin(),nums.begin()+n,[](const auto& a,const auto& b){
        return abs(a[0]-a[1])<abs(b[0]-b[1]);
    });
    int maxa=0;
    int maxb=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(nums[i][0]<=nums[i][1]){
            ans=max(ans,maxa+nums[i][0]);
        }
        else{
            ans=max(ans,maxb+nums[i][1]);
        }
        maxa=max(maxa,nums[i][0]);
        maxb=max(maxb,nums[i][1]);
    }
    return ans;
}
int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> nums[i][0] >> nums[i][1];
    }
    int ans=compute();
    cout << fixed << setprecision(1) << ans/2.0 << endl;
}

//https://leetcode.cn/problems/largest-component-size-by-common-factor
class Solution {
public:
    static const int maxn=100001;
    vector<int>factors; //factors[i]=x,i这个质数因子，最早被下标x的数字拥有
    vector<int>father;
    vector<int>sizes;
    void build(int n){
        factors.resize(maxn,-1);
        father.resize(n);
        sizes.resize(n,1);
        for(int i=0;i<n;i++){
            father[i]=i;
        }
    }
    int find(int i){
        if(father[i]!=i){
            father[i]=find(father[i]);
        }
        return father[i];
    }
    void unite(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx!=fy){
            father[fx]=fy;
            sizes[fy]+=sizes[fx];
        }
    }
    int maxsize(int n){
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(sizes[i],ans);
        }
        return ans;
    }
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        build(n);
        for(int i=0,x;i<n;i++){
            x=nums[i];
            for(int j=2;j*j<=x;j++){
                if(x%j==0){
                    if(factors[j]==-1){
                        factors[j]=i;
                    }
                    else{
                        unite(factors[j],i);
                    }
                    while(x%j==0){
                        x/=j;
                    }
                }
            }
            if(x>1){
                if(factors[x]==-1){
                    factors[x]=i;
                }
                else{
                    unite(factors[x],i);
                }
            }
        }
        return maxsize(n);
    }
};

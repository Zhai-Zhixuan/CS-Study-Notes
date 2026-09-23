//https://leetcode.cn/problems/jian-sheng-zi-ii-lcof/description/
class Solution {
public:
    const int mod=1000000007;
    long long power(int a,int b){
        long long ans=1;
        while(b){
            if(b&1){
                ans=(ans*a)%mod;
            }
            a=(long long)a*a%mod;
            b>>=1;
        }
        return ans;
    }
    int cuttingBamboo(int bamboo_len) {
        if(bamboo_len==2){
            return 1;
        }
        if(bamboo_len==3){
            return 2;
        }
        // 4 -> 2 * 2
        // 5 -> 3 * 2
        // 6 -> 3 * 3
        // 7 -> 3 * 2 * 2
        // 8 -> 3 * 3 * 2 
        // 9 -> 3 * 3 * 3
        // 10 -> 3 * 3 * 2 * 2
        int x = bamboo_len%3==0?1:(bamboo_len%3==1?4:2);
        int n = (x==1?bamboo_len:bamboo_len-x)/3;
        return power(3,n)*x%mod;
    }
};

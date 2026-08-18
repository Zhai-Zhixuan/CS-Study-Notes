//给定整数n，返回1~n范围上所有的质数
/**Sieve of Eratosthenes 埃氏筛
时间复杂度：O(n*log(logn))
原理：
一个质数的倍数一定是合数
核心思想：
1. 列出从 2 到 N 的所有整数
2. 从最小的质数 2 开始，将其所有倍数标记为合数
3. 找到下一个未被标记的数，它一定是质数，重复标记它的倍数
4. 重复直到处理完所有数
优化：
1.合数n的质因子必定小于等于根号n，所以只判断[2,n**0.5]内有没有质因子即可
2.若j每次都从2*i开始遍历，而j已被更小的2等质因子整除标记，发生重复标记，只需从i*i开始遍历即可**/
const int N=1000000;
void E_sieve() {
    vector<bool>is_prime(N,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<=N;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=N;j+=i){
                is_prime[j]=false;
            }
        }
    }
}

/**Linear Sieve 欧拉筛
时间复杂度：O(n)**/
class Solution {
public:
    static int solve(int n){
        if(n<=1) return 0;
        //visit[i]=true,代表i是合数
        //visit[i]=false,代表i是质数
        vector<bool>visit(n+1,false);
        vector<int>prime(n/2+1);
        int cnt=0;
        for(int i=2;i<=n;i++){
            if(!visit[i]){
                prime[cnt++]=i;
            }
            for(int j=0;j<cnt;j++){
                if(i*prime[j]>n){
                    break;
                }
                visit[i*prime[j]]=true;
                if(i%prime[j]==0){
                    break;
                }
            }
        }
        return cnt;
    }
    int countPrimes(int n) {
        return solve(n-1);
    }
};

//https://leetcode.cn/problems/count-primes

//https://www.nowcoder.com/share/jump/1997206311789465653711
#include <stdio.h>

int main() {
    long long n;
    scanf("%lld",&n);
    long long count=0;
    if((n&1)!=0){
    count=-1;
    }
    else if(n<18){
        if(n==6||n==8){
            count=1;
        }
        else if(n==12||n==14||n==16){
            count=2;
        }
        else count=-1;
    }
    else count=(n-18)/8+3;
    printf("%lld",count);
    return 0;
}

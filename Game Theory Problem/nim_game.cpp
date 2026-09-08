//https://www.luogu.com.cn/problem/P2197
#include<iostream>
using namespace std;
int main(){    
  int t;    
  cin >> t;    
  while(t--){        
    int n;        
    cin >> n;        
    int eor=0;        
    int x;        
    for(int i=0;i<n;i++){            
      cin >> x;            
      eor^=x;        
    }        
    if(eor!=0){            
      cout << "Yes\n";        
    }        
    else{            
      cout << "No\n";        
    }    
  }
}

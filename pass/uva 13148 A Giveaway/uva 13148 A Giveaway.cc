// type // float // numbers
// n=k^6
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   auto p6=[](int x){
      return x*x*x*x*x*x;
   };
   while(1){
      int n;
      scanf("%d",&n);
      if(0==n){
         break;
      }
      int k=exp(log(n)/6.0);
      if(p6(k)==n||p6(k+1)==n||p6(k-1)==n){
         printf("Special\n");
      }else{
         printf("Ordinary\n");
      }
   }



   return 0;
}

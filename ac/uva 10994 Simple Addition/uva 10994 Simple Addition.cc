// tag // numbers // divisibility // self-similarity
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long int LLI;
LLI sF(int n){
   if(n<=0){
      return 0;
   }
   int q=n/10;
   int r=n%10;
   return LLI(q)*45+(r*(r+1))/2+sF(q);
}

int main(){

   while(1){
      int a,b;
      scanf("%d%d",&a,&b);
      if(a<0&&b<0){
         break;
      }
      printf("%lld\n",sF(b)-sF(a-1));

   }

   return 0;
}

// tag // prime number // Legendre
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   typedef long long int LLI;
   while(1){
      LLI n; int b;
      scanf("%lld%d",&n,&b);
      if(0==(n+b)){
         break;
      }
      //find the largest prime factor
      int p=1;
      if(b%2==0){p=2;b/=2;}
      if(b%3==0){p=3;b/=3;}
      int d=5;int plus=2;
      while(d*d<b){//square free
         if(b%d==0){
            p=d;
            b/=d;
         }
         d+=plus;
         plus=6-plus;
      }
      if(b>1){p=b;}


      //for a given tp=p^l divide the [1,n] interval into
      // [m*tp,(m+1)*tp) subintervals, x/tp is constant and we know
      // the length: sum(sum(x/tp))=tp*(k*(k-1))/2
      // the closing [(m+1)*tp,n] interval can be treated in a similar way
      LLI ans=0;
      LLI tp=1;
      while(1){
         tp*=p;
         if(tp>n){break;}
         LLI r=n%tp;
         LLI k=n/tp;
         ans+=tp*((k*(k-1))/2)+(k*(r+1));
      }
      printf("%lld\n",ans);
   }// while there are real cases

   return 0;
}

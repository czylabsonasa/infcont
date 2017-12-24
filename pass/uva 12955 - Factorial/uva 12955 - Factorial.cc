// type // search // greedy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int fakt[11]={1,1,1*2,1*2*3,1*2*3*4,1*2*3*4*5,
   1*2*3*4*5*6,1*2*3*4*5*6*7,1*2*3*4*5*6*7*8,1*2*3*4*5*6*7*8*9,
   1*2*3*4*5*6*7*8*9*10
   };
   int n;
   while(1==scanf("%d",&n)){
      int ans=0;
      int k=10;
      while(n>0){
         if(fakt[k]<=n){
            int q=n/fakt[k];
            ans+=q;
            n-=q*fakt[k];
         }
         --k;
      }
      printf("%d\n",ans);
   }

   return 0;
}

// type // search
// special cases
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   typedef unsigned long long int LLI;
   int dig[16];
   LLI pw[16];

   int esetek;scanf("%d",&esetek);
   while(esetek--){
      LLI n;scanf("%llu",&n);
      bool ans=true;
      while(n>9){
         ans=false;
         int ndig=0;
         LLI tn=n;
         while(tn>0){
            int r=tn%10;
            if(r){
               dig[ndig++]=r;
            }
            tn=tn/10;
         }

         int i=0;
         while(i<ndig&&dig[i]<2){
            i++;
         }
         if(i==ndig){// 10,11,10101 etc.
            break;
         }

         for(int i=0;i<ndig;i++){
            pw[i]=dig[i]*dig[i];
         }
         LLI sum;
         while(1){
            sum=0;
            for(int i=0;i<ndig;i++){
               sum+=pw[i];
            }
            if(sum>=n){
               break;
            }
            for(int i=0;i<ndig;i++){
               pw[i]=pw[i]*dig[i];
            }
         }
         if(sum==n){
            ans=true;
         }
         break;
      }

      if(ans){
         printf("Armstrong\n");
      }else{
         printf("Not Armstrong\n");
      }
   }

   return 0;
}

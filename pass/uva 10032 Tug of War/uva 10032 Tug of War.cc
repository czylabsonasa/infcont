// type // dp // bitset

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int const N=100+6;
int const W=450+6;
typedef unsigned long long int LLI;
LLI info[(N/2)*(W/2)];
int weights[N];

int main(){
   int esetek;scanf("%d",&esetek);
   while(1){
      int n;scanf("%d",&n);
      int sw=0;
      for(int i=0;i<n;i++){
         scanf("%d",&weights[i]);
         sw+=weights[i];
      }

      int ans=0;
      if(n>1){
         int sw2=sw/2;
         int n2=(n/2)+(n%2);
         for(int i=0;i<=sw2;i++){
            info[i]=0;
         }
         info[0]=1;
         int mx=0;
         for(int i=0;i<n;i++){
            int wi=weights[i];
            int mx=min(mx+wi,sw2);
            for(int from=mx-wi,to=mx;from>=0;from--,to--){
               info[to]|=(info[from]<<1);
            }
         }

         ans=sw2;
         LLI mask=(LLI(1)<<n2);
         if(n%2==0){
            while(!(info[ans]&mask)){
               ans--;
            }
         }else{
            while(!(info[ans]&mask)&&!(info[ans]&(mask>>1))){
               ans--;
            }
         }
      }
      printf("%d %d\n",ans,sw-ans);
      if(--esetek){
         printf("\n");
      }else{
         break;
      }
   }

   return 0;
}

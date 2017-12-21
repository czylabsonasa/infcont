// type // divisors
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int n;scanf("%d",&n);
      int sd=0;
      int d=2;
      while(d<n){
         if(0==n%d){
            sd+=d;
         }
         d++;
      }
      if(n>1){++sd;}

      if(sd<n){
         printf("deficient\n");
         continue;
      }
      if(sd>n){
         printf("abundant\n");
         continue;
      }
      printf("perfect\n");
   }

   return 0;
}

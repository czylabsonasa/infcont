// type // coin change // dp
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
   int bars[32];
   char f[1111];
   int esetek; scanf("%d", &esetek);
   while(esetek--){
      int tar;
      scanf("%d", &tar);
      int nb;
      scanf("%d", &nb);
      for(int i=0; i<nb; i++){
         scanf("%d", &bars[i]);
      }
      fill(f,f+tar+1,0);
      f[0]=1;
      int mx=0;
      for(int i=nb-1; i>=0 && !f[tar]; i--){
         int b=bars[i];
         if(b>tar){continue;}
         for(int from=min(tar-b,mx), to=from+b; from>=0; from--, to-- ){
            f[to]|=f[from];
         }
         mx=min(mx+b, tar);
      }
      if(f[tar]){
         printf("YES\n");
      }else{
         printf("NO\n");
      }

   }

   return 0;
}

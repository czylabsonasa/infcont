// type // bit // search
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   char form[64];
   char volt[32];
   int esetek;scanf("%d",&esetek);
   while(esetek--){
      unsigned int t;scanf("%u",&t);
      int i=64;
      while(i>32){
         form[--i]=t&1;
         t>>=1;
      }
      while(i>0){
         --i;
         form[i]=form[i+32];
         volt[i]=0;
      }
      int akt=0;
      i=59;
      while(i<64){
         akt=(akt<<1)+form[i];
         i++;
      }
      volt[akt]=1;
      i=58;
      while(i>27){
         akt>>=1;
         akt+=16*form[i];
         if(!volt[akt]){
            volt[akt]=1;
         }else{
            break;
         }
         i--;
      }
      if(i>27){
         printf("no\n");
      }else{
         printf("yes\n");
      }
   }
   return 0;
}

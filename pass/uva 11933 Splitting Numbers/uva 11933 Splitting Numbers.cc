// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   typedef unsigned int UI;
   while(1){
      UI a;
      scanf("%u",&a);
      if(0==a){
         break;
      }
      UI b=0;
      UI m=1;
      int tob=0;//b-be kerul?
      
      for(int i=0;i<32;i++){
         if(m&a){
            if(tob){
               b=b|m;
            }
            tob=1-tob;
         }
         m=m<<1;
      }
      a=a^b;
      printf("%u %u\n",a,b);
   }

   return 0;
}

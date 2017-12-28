// type // divisibility
// jol el lehet bonyolitani, ha optimalisan akarod megirni
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek; scanf("%d", &esetek);
   while(esetek--){
      int A,B,C;
      scanf("%d%d%d", &A, &B, &C);
      bool found=false;
      int sx=0,sy=0,sz=0;
      //negative x
      for(int x=-B; x<=B&&false==found; x++){
         int ax=abs(x);
         if(0==ax || 0!=B%ax || ax*ax>B/ax || ax>(2*C)/(3*ax)){
            continue;
         }
         int tB=B/x;
         int tC=C-ax*ax;
         for(int y=x; y<=abs(tB); y++){
            int ay=abs(y);
            if(0==y || 0!= tB%ay || ay*ay>tC/2){
               continue;
            }
            int z=tB/y;
            if(z<y){
               continue;
            }
            if(x+y+z==A && tC==ay*ay+z*z){
               sx=x;sy=y;sz=z;
               found=true;
               break;
            }
         }
      }

      if(found){
         printf("%d %d %d\n", sx, sy, sz);
      }else{
         printf("No solution.\n");
      }

   }


   return 0;
}

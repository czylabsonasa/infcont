// type // divisibility // search // brute-force
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
      for(int x=-B; x<=B && false==found; x++){//B=0-t nem kezeli
         if(0==x || 0!=B%x || 3*x + 3 > A || 3*x*x + 6*x + 5 > C ) {
            continue;
         }
         int tB = B/x;
         int tA = A - x;
         int tC = C - x*x;
         for(int y=x+1; y<=abs(tB) ; y++){
            if(0==y || 0!=tB%y || 2*y + 1 > tA || 2*y*y + 2*y + 1 > C){
               continue;
            }
            int z=tB/y;
            if(z <= y){
               continue;
            }
//printf("   %d %d %d\n",x,y,z);
            if(y+z==tA && y*y+z*z==tC){
               sx=x;sy=y;sz=z;
               found=true;
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

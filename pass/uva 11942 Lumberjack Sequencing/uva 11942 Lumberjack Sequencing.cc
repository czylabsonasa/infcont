// type // implementation //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   printf("Lumberjacks:\n");
   while(esetek--){
      int l0,l1;scanf("%d%d",&l0,&l1);
      int d=((l0<l1)?1:-1);
      int i=2;
      while(i<10){
         l0=l1;
         scanf("%d",&l1);
         int td=((l0<l1)?1:-1);
         i++;
         if(d!=td){
            d=0;
            break;
         }
      }
      if(0==d){
         printf("Unordered\n");
      }else{
         printf("Ordered\n");
      }
      while(i<10){
         scanf("%d",&l1);
         i++;
      }
   }
   return 0;
}

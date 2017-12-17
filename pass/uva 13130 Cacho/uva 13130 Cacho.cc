// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int a[6];a[5]=100000;
   int esetek;scanf("%d",&esetek);
   while(esetek--){
      for(int i=0;i<5;i++){
         scanf("%d",&a[i]);
      }
      int i=1;
      while(1==a[i]-a[i-1]){
         ++i;
      }
      if(i==5){
         printf("Y\n");
      }else{
         printf("N\n");
      }
   }

   return 0;
}

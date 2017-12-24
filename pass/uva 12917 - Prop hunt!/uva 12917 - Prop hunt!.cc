// type // simple
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int o,p,h;
   while(3==scanf("%d%d%d",&p,&h,&o)){
      if(o-p>=h){
         printf("Props win!\n");
      }else{
         printf("Hunters win!\n");
      }
   }

   return 0;
}

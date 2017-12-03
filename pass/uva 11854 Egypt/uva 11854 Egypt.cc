// type // numbers // easy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){

   while(1){
      typedef unsigned int UI;//sima int is eleg lenne
      UI a,b,c;scanf("%u%u%u",&a,&b,&c);
      if(0==a+b+c){
         break;
      }
      if(a>b){swap(a,b);}
      if(b>c){swap(b,c);}
      if(a>b){swap(a,b);}
      if(a*a+b*b==c*c){
         printf("right\n");
      }else{
         printf("wrong\n");
      }
   }

   return 0;
}

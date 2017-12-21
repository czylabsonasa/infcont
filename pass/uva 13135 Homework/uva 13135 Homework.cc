// type // binomial coeff, permutation
// 2s=x(x-1)<(x-0.5)^2
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   while(esetek--){
      int s;scanf("%d",&s);
      int x=ceil(sqrt(2*s)-1.5);
      while((x+2)*(x+1)<2*s){++x;}
      if((x+2)*(x+1)==2*s){
         printf("%d\n",x);
      }else{
         printf("No solution\n");
      }
   }
   return 0;
}

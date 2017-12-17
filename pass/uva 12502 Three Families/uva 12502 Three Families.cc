// type // ad-hoc
// subtract the third, examine the proportion
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int a,b,paid;scanf("%d%d%d",&a,&b,&paid);
      if(b>=2*a){
         printf("0\n");
         continue;
      }
      if(a>=2*b){
         printf("%d\n",paid);
         continue;
      }

      printf("%d\n",((2*a-b)*paid)/(a+b));
   }

   return 0;
}

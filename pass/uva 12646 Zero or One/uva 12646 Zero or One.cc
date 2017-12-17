// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   char ans[8]={
   '*',//000
   'C',//001
   'B',//010
   'A',//011
   'A',//100
   'B',//101
   'C',//110
   '*' //111
   };
   int a,b,c;
   while(3==scanf("%d%d%d",&a,&b,&c)){
      printf("%c\n",ans[4*a+2*b+c]);
   }

   return 0;
}

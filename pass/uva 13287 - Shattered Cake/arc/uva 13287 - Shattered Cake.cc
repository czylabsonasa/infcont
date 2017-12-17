// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){

   int w,n;
   while(1==scanf("%d",&w)){
      scanf("%d",&n);
      int lw=0;
      for(int i=0;i<n;i++){
         int a,b;
         scanf("%d%d",&a,&b);
         lw+=a*b;
      }
      printf("%d\n",lw/w);
   }

   return 0;
}

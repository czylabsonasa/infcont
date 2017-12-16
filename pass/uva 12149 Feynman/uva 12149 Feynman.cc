// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   while(1){
      int n;scanf("%d",&n);
      if(0==n){
         break;
      }
      printf("%d\n",(n*(n+1)*(2*n+1))/6);

   }

   return 0;
}

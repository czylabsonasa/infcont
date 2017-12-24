// type // quadratic equation
//
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   while(1){
      int s;scanf("%d",&s);
      if(0==s){
         break;
      }
      int n=int(0.5*(sqrt(1+8*(s+1))-1));
      int ss;
      while(1){//at most two tries
         ss=(n*(n+1))/2;
         if(ss-s>=1&&ss-s<=n){
            break;
         }
         n++;
      }
      printf("%d %d\n",ss-s,n);

   }

   return 0;
}

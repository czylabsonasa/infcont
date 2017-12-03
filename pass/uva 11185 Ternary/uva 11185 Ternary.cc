// tag // number // easy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   char ter[77+2];ter[78]=0;ter[77]='\n';
   while(1){
      int n;scanf("%d",&n);
      if(n<0){
         break;
      }
      char*p=&ter[77];
      while(1){
         *(--p)='0'+(n%3);
         n/=3;
         if(0==n){
            break;
         }
      }
      printf("%s",p);
   }
   return 0;
}

// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int eset=0;
   while(1){
      int n;scanf("%d",&n);
      if(0==n){
         break;
      }
      int e=0;
      for(int i=0;i<n;i++){
         int t;scanf("%d",&t);
         e+=(t>0);
      }
      printf("Case %d: %d\n",++eset,2*e-n);
   }

   return 0;
}

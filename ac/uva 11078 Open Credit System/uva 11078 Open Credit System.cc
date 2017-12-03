// tag // search // easy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek; scanf("%d",&esetek);
   while(esetek--){
      int n;scanf("%d",&n);
      int a,b;scanf("%d%d",&a,&b);
      int mop=max(a,b); //max of the prev ones
      int mkd=a-b; //max known difference
      n-=2;
      while(n--){
         scanf("%d",&a);
         mkd=max(mkd,mop-a);
         mop=max(mop,a);
      }
      printf("%d\n",mkd);
   }
   return 0;
}

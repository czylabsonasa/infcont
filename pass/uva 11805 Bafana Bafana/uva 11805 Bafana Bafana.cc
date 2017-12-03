// type // numbers // easy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){

   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int n,k,p;scanf("%d%d%d",&n,&k,&p);
      printf("Case %d: %d\n",eset,(k-1+p)%n+1);
   }

   return 0;
}

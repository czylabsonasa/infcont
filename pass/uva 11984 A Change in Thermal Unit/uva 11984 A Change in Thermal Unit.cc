// type // easy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int c,d;   
      scanf("%d%d",&c,&d);
      printf("Case %d: %.2lf\n",eset,c+5.0*d/9.0);
   }

   

   return 0;
}

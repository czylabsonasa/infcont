// type // high school geom // circle
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek; scanf("%d", &esetek);
   while(esetek--){
      int x,y,r;
      scanf("%d%d%d", &x, &y, &r);
      double a=sqrt(x*x + y*y);
      printf("%.2lf %.2lf\n", r-a+1e-12, r+a);
   }

   return 0;
}

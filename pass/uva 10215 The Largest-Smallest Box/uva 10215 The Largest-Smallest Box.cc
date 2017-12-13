// type // quadratics // floating point
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define EP 1e-9
int main(){
   double L,W;
   while(2==scanf("%lf%lf",&L,&W)){
      double D=sqrt((L+W)*(L+W)-3.0*L*W);
      double x1=((L+W)-D)/6.0;
      double x2=0.5*min(L,W);
      printf("%.3lf 0.000 %.3lf\n",x1+EP,x2+EP);
   }

   return 0;
}

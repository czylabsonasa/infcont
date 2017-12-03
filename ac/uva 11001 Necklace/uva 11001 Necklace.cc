// tag // highschool // quadratic polynomial extrema
// no need to sqrt, only examine the extrema(s) of
// k*(V/V0)-k^2
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   while(1){
      double V,V0;scanf("%lf%lf",&V,&V0);
      if(V+V0<1e-15){
         break;
      }
      int k=0;
      if(!(V<V0)){
         double b=V/V0;
         k=floor(0.5*b);
         double fk=k*b-k*k;
         double fkalt=(k+1)*b-(k+1)*(k+1);//an alternative
         if(abs(fk-fkalt)<1e-15){
            k=0;
         }else{
            if(fkalt>fk){
               k++;
            }
         }

      }

      printf("%d\n",k);
   }
   return 0;
}

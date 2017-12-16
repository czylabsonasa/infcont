// type // area
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   double mpi=acos(-1.0);
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int L2;scanf("%d",&L2);
      L2=L2*L2;
      double r=0.04*L2*mpi+1e-12;
      double g=0.6*L2-r+1e-12;

      printf("%.2lf %.2lf\n",r,g);
   }

   return 0;
}

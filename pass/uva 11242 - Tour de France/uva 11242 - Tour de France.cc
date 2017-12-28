// type // search // sort
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int front[16],rear[16];
   double d[16*16];
   int nf, nr;
   while(2==scanf("%d%d", &nf, &nr)){
      for(int i=0; i<nf; i++){
         scanf("%d", &front[i]);
      }
      for(int i=0; i<nr; i++){
         scanf("%d", &rear[i]);
      }
      int nd=0;
      for(int i=0; i<nf; i++){
         double fi=double(front[i]);
         for(int j=0; j<nr; j++){
            d[nd++]=fi/double(rear[j]);
         }
      }
      double mx=1.0;
      if(nd>1){//!!!
         sort(d, d+nd);
         mx=d[1]/d[0];
         for(int i=2; i<nd; i++){
            mx=max(mx, d[i]/d[i-1]);
         }
      }
      printf("%.2lf\n", mx+1e-9);

   }


   return 0;
}

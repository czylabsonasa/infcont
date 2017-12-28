// type // high-school math // circle
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <tuple>
using namespace std;

tuple<int,int,int> rts[128];
#define X get<0>
#define Y get<1>
#define R2 get<2>


int main(){
   int esetek; scanf("%d", &esetek);
   for(int eset=1; eset<=esetek; eset++){
      int nr, nq; scanf("%d%d", &nr, &nq);
      for(int i=0; i<nr; i++){
         scanf("%d%d%d", &X(rts[i]), &Y(rts[i]), &R2(rts[i]));
         R2(rts[i])*=R2(rts[i]);
      }
      printf("Case %d:\n", eset);
      for(int i=0; i<nq; i++){
         int x, y;
         scanf("%d%d", &x, &y);
         bool ok = false;
         for(int j=0; j<nr; j++){
            int d2=(x-X(rts[j]))*(x-X(rts[j]))+(y-Y(rts[j]))*(y-Y(rts[j]));
            if(d2 <= R2(rts[j])){
               ok = true;
               break;
            }
         }
         if(ok){
            printf("Yes\n");
         }else{
            printf("No\n");
         }
      }


   }

   return 0;
}

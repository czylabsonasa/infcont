// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int nw;scanf("%d",&nw);
      int pw;scanf("%d",&pw);
      int hj=0,lj=0;
      for(int i=1;i<nw;i++){
         int w;scanf("%d",&w);
         if(w>pw){
            ++hj;
         }else{
            if(w<pw){
               ++lj;
            }
         }
         pw=w;
      }

      printf("Case %d: %d %d\n",eset,hj,lj);
   }

   return 0;
}

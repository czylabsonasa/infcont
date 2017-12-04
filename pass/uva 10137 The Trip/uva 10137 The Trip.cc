// type // number // remainder //
// rewrite an old wa
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int spent[1008];
int main(){
   while(1){
      int n;scanf("%d",&n);
      if(0==n){
         break;
      }
      int all=0;
      for(int i=0;i<n;i++){
         int d,c;scanf("%d.%d",&d,&c);
         spent[i]=100*d+c;
//fprintf(stderr,"%d %d\n",i,spent[i]);
         all+=spent[i];
      }
      int q=all/n;
      int r=all%n;
      int exc=0;//exchange
      for(int i=0;i<n;i++){
         int spi=spent[i];
         if(spi>q){
            if(r>0){
               exc+=(spi-q-1);
               --r;
            }else{
               exc+=(spi-q);
            }
         }
      }
      q=exc/100;
      r=exc%100;
      printf("$%d.%02d\n",q,r);

   }
   return 0;
}

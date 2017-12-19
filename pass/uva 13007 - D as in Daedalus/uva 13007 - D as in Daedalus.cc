// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int vals[]={-1000000000,1,10,100,1000,10000,1000000000};
int main(){
   int np,nr;//players,round
   while(2==scanf("%d%d",&np,&nr)){
      int real=0;
      int opt=0;
      for(int ri=0;ri<nr;ri++){
         int bank;scanf("%d",&bank);
         int d;scanf("%d",&d);
         int sum=d;
         for(int i=1;i<np;i++){
            int t;scanf("%d",&t);
            sum+=t;
         }
         if(sum<=bank){
            real+=d;
         }
         sum-=d;
         int di=5;
         while(sum+vals[di]>bank){--di;}
         if(di>0){
            opt+=vals[di];
         }
      }//rounds
      printf("%d\n",opt-real);
   }//esetek

   return 0;
}

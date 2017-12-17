// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int opt=1000000;
      int n,a,b;
      scanf("%d%d:%d",&n,&a,&b);
      int s=a*60+b;
      for(int i=0;i<n;i++){
         int ta,tb,len;
         scanf("%d:%d%d",&ta,&tb,&len);
         int ts=ta*60+tb;
         if(ts<s){ts+=1440;}
         if(ts>=s&&ts-s+len<opt){
            opt=ts-s+len;
         }
      }

      printf("Case %d: %d\n",eset,opt);
   }

   return 0;
}

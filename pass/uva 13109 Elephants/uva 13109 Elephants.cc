// type // sort // greedy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int w[100008];
int main(){
   int esetek;scanf("%d",&esetek);
   while(esetek--){
      int noe,cow;//no of elephants, cap. of web
      scanf("%d%d",&noe,&cow);
      int sum=0; //lim: 10^5*10^4
      for(int i=0;i<noe;i++){
         scanf("%d",&w[i]);
         sum+=w[i];
      }
      int ans=noe;
      if(sum>cow){
         sort(w,w+noe);
         ans=0;
         while(cow-w[ans]>=0){
            cow-=w[ans];
            ans++;
         }
      }
      printf("%d\n",ans);
   }
   return 0;
}

// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int const N=100+4;
int const W=450+4;
char info[(N*W)/2][N/2];
char reach[(N*W)/2];
int weights[N];

int main(){
   int esetek; scanf("%d",&esetek);
   while(1){
      int n;scanf("%d",&n);
      int sw=0;
      for(int i=0;i<n;i++){
         scanf("%d",&weights[i]);
         sw+=weights[i];
      }
      int ans=0;
      if(1<n){
         int n2=n/2+(n%2);
         int sw2=sw/2;
         for(int i=0;i<=sw2;i++){
            reach[i]=0;
            for(int j=0;j<=n2;j++){
               info[i][j]=0;
            }
         }
         reach[0]=1;info[0][0]=1;

         int mx=0;
         for(int i=0;i<n;i++){
            int wi=weights[i];
            mx=min(mx+wi,sw2);
            for(int to=mx,from=mx-wi;from>=0;from--,to--){
               if(reach[from]){
                  reach[to]=1;
                  for(int j=0;j<n2;j++){
                     info[to][j+1]|=info[from][j];
                  }
               }
            }
         }
         ans=sw2;
         while(1){
            if(info[ans][n2]){
               break;
            }
            ans--;
         }

      }//n>1

      printf("%d %d\n",ans,sw-ans);
      if(--esetek){//assuming at least one case
         printf("\n");
      }else{
         break;
      }

   }

   return 0;
}

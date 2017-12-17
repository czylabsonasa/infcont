// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char ret[10008]={0};
int main(){
   int n,r;
   while(2==scanf("%d%d",&n,&r)){
      if(r<n){
         for(int i=0;i<r;i++){
            int t;scanf("%d",&t);
            ret[t]=1;
         }
      }else{
         for(int i=0;i<r;i++){
            int t;scanf("%d",&t);
         }
      }

      if(r>=n){
         printf("*\n");
      }else{
         for(int i=1;i<=n;i++){
            if(0==ret[i]){
               printf("%d ",i);
            }else{
               ret[i]=0;
            }
         }
         printf("\n");
      }
   }
   return 0;
}

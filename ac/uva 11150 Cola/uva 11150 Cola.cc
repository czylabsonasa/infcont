// tag // number // implementation
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int pre[222]={0,1,3};//wa volt mert pre[2]=2-t irtam
   for(int n=3;n<=200;n++){
      int ans=n;
      int r=n;
      while(1){
         if(r<3){
            break;
         }
         ans+=(r/3);
         r=((r/3)+(r%3));
      }
//printf("%d %d %d\n",n,ans,r); //valami szabalyszeruseg van
      if(r==2){
         ++ans;
      }
      pre[n]=ans;
   }

   int n;
   while(1==scanf("%d",&n)){
      printf("%d\n",pre[n]);
   }


   return 0;
}

// type // coin change // dp
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int const S=100;
int s[S+1];
int const R=10000;
char reach[R+1];
int main(){
   while(1){
      int n,g;scanf("%d%d",&n,&g);
      if(0==n+g){
         break;
      }
      for(int i=1;i<=n;i++){
         int a,b;
         scanf("%d.%d",&a,&b);
         s[i]=100*a+b;
      }
      if(s[g]>5000){
         printf("100.00\n");
         continue;
      }
      memset(reach,0,R+1);
      reach[0]=1;
      int mx=0;
      for(int i=1;i<=n;i++){
         if(g==i){
            continue;
         }
         for(int from=mx,to=mx+s[i];from>=0;from--,to--){
            reach[to]|=reach[from];
         }
         mx+=s[i];
      }
      int sum=5001-s[g];
      while(0==reach[sum]){
         ++sum;
      }
      double ans=100.0*double(s[g])/double(sum+s[g]);

      printf("%.02lf\n",ans+1e-9);


   }

   return 0;
}

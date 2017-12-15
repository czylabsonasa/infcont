// type // formula interpretation // gcd
#include <cstdio>
#include <cmath>
#include <algorithm>
int gcd(int a0,int a1){
   int a2;
   while((a2=(a0%a1))){
      a0=a1;
      a1=a2;
   }
   return a1;
}

using namespace std;
int main(){
   int const N=500;
   int preComp[N+1];
   preComp[0]=preComp[1]=0;
   for(int i=2;i<=N;i++){
      int s=preComp[i-1];
      for(int j=1;j<i;j++){
         s+=gcd(i,j);
      }
      preComp[i]=s;
   }

   while(1){
      int n;scanf("%d",&n);
      if(0==n){
         break;
      }
      printf("%d\n",preComp[n]);

   }

   return 0;
}

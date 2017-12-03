// type // coin chage // dp
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int const W=10000;
long long int ways[W+11];
int const C=21;
int coin[C];
int main(){
   for(int i=0;i<C;i++){
      coin[i]=(i+1)*(i+1)*(i+1);
   }
   ways[0]=1;
   for(int i=0;i<C;i++){
      int ac=coin[i];
      for(int j=0;j+ac<=W;j++){
         ways[j+ac]+=ways[j];
      }
   }

   int a;
   while(1==scanf("%d",&a)){
      printf("%lld\n",ways[a]);
   }




   return 0;
}

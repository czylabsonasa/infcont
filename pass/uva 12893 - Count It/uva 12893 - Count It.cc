// type // simple // 2-base numbers
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long int LLI;
int main(){
   int esetek;scanf("%d",&esetek);
   while(esetek--){
      LLI n;scanf("%llu",&n);
      int ones=0;
      while(n>0){
         ones+=n&1;
         n>>=1;
      }
      printf("%d\n",ones);
   }
   return 0;
}

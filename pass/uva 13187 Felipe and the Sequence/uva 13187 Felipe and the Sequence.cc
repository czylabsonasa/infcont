// type // math // sequence // rationalilzing denominator
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   long long int S;
   int esetek;scanf("%d",&esetek);
   while(esetek--){
      scanf("%lld",&S);
      printf("%lld\n",(S+1)*(S+1)-1);
   }


   return 0;
}

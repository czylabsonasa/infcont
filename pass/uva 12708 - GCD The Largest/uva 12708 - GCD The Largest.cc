// type // easy
//n=2k(+1) -> k

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek; scanf("%d", &esetek);
   while(esetek--){
      unsigned long long int n; scanf("%llu", &n);
      printf("%llu\n",n/2);
   }
   return 0;
}

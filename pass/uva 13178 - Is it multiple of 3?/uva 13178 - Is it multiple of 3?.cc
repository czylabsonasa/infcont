// type // divisibility
// a neghbouring digits can be grouped together to for a big digit

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   typedef unsigned long long int LLI;
   int esetek;scanf("%d",&esetek);
   while(esetek--){
      LLI n;scanf("%llu",&n);
      if(((n*(n+1))/2)%3){
         printf("NO\n");
      }else{
         printf("YES\n");
      }
   }
   return 0;
}

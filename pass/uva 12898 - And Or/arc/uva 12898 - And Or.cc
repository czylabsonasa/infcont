// type // numbers // base 2 representation
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long int LLI;
int main(){
   int esetek;scanf("%d",&esetek);
   for(int eset=1; eset<=esetek; eset++){
      LLI A, B; scanf("%llu%llu", &A, &B);
      LLI resOR=0ULL, resAND=0ULL,
      diff = B-A, egy = 1ULL,
      part = 0;
      while(egy && B>=egy){
         bool ch = (egy<=diff+part);//there is a change in (A,B]
         if(egy & A){
            resOR = resOR|egy;
            if(!ch){
               resAND = resAND|egy;
            }
            part = part|egy;
         }else{
            if(ch){
               resOR = resOR|egy;
            }
         }
         egy = (egy << 1);

      }

      printf("Case %d: %llu %llu\n", eset, resOR, resAND );
   }

   return 0;
}

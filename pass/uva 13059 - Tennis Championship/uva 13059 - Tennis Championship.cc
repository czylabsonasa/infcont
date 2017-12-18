// type // easy
// can be solved in a more difficult way
// another form of p-1
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   typedef unsigned long long int LLI;
   LLI p;
   while(1==scanf("%llu",&p)){
      //~ LLI r=0;
      //~ while(p>1){
         //~ int c=p%2;
         //~ p/=2;
         //~ r+=p;
         //~ p+=c;
      //~ }
      printf("%llu\n",p-1);
   }

   return 0;
}

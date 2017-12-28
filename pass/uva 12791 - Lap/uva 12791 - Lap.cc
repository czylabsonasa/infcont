// type // high-school math
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int ts, tf;
   while(2==scanf("%d%d",&tf, &ts)){
      int ans=(ts%(ts-tf)?1:0) + ts/(ts-tf);
      printf("%d\n", ans);
   }

   return 0;
}

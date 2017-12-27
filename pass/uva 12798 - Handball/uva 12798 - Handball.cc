// type // easy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int np, nm;
   while(2==scanf("%d%d", &np, &nm)){
      int ans=0;
      for(int i=0; i<np; i++){
         int part=0;
         for(int j=0; j<nm; j++){
            int t; scanf("%d", &t);
            part += (t>0);
         }
         ans += (part == nm);
      }
      printf("%d\n", ans);
   }
   return 0;
}

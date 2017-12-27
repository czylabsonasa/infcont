// type // high-school math
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek; scanf("%d", &esetek);
   for(int eset=1; eset<=esetek; eset++){
      int n, k, x;
      scanf("%d%d%d", &n, &k, &x);
      int ans = (n*(n+1))/2-(k*x+(k*(k-1))/2);
      printf("Case %d: %d\n", eset, ans);
   }

   return 0;
}

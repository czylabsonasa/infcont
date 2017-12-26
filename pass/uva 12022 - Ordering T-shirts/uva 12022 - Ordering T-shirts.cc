// type // enumeration // dp
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long int LLI;
int const N=11;
LLI dp[N+1][N+1];
int main(){
   dp[1][1] = 1; dp[1][0] = 1;
   dp[2][1] = 1; dp[2][2] = 2; dp[2][0] = 3;
   for(int n=3; n<=N; n++){
      dp[n][1] = 1;
      for(int k=2; k<n; k++){
         dp[n][k] = k*(dp[n-1][k-1]+dp[n-1][k]);
      }
      dp[n][n]=dp[n-1][n-1]*n;

      LLI& s=dp[n][0]; s=0;
      for(int k=1; k<=n; k++){
         s += dp[n][k];
      }
   }

   int esetek; scanf("%d", &esetek);
   while(esetek--){
      int n;
      scanf("%d", &n);
      printf("%llu\n", dp[n][0]);
   }


   return 0;
}

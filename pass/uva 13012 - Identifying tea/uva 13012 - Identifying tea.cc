// type // easy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   
   int t;
   while(1==scanf("%d",&t)){
      int ok=0;
      for(int i=0;i<5;i++){
         int ans;scanf("%d",&ans);
         ok+=(ans==t);
      }
      printf("%d\n",ok);
   }

   return 0;
}

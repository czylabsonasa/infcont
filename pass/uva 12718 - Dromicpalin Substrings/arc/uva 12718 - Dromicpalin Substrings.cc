// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char pali[1024];
int info[1024];
char nodd[1024];
int main(){
   int esetek; scanf("%d", &esetek);
   for(int eset=1; eset<=esetek; eset++){
      scanf("%s",pali);
      int ans = 0;
      for(int i=0; pali[i]; i++){
         ++ans;
         int mask = (1<<(pali[i]-'a'));
         info[i] = mask;
         nodd[i] = 1;
         for(int j=i-1; j>=0; j--){
            if(mask & info[j]){
               --nodd[j];
            }else{
               ++nodd[j];
            }
            ans += (nodd[j]<2);
            info[j]=info[j]^mask;
         }
      }

      printf("Case %d: %d\n", eset, ans);
   }

   return 0;
}

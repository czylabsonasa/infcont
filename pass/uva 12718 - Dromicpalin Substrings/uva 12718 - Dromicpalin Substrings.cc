// type // array - bit manipulation // brute force
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
         register int mask = (1<<(pali[i]-'a'));
         info[i] = mask;
         nodd[i] = 1;
         register int* infj=&info[i-1];
         register char* ndj=&nodd[i-1];
         for(int j=i-1; j>=0; j--,infj--,ndj--){
            if(mask & *infj){
               --(*ndj);
            }else{
               ++(*ndj);
            }
            ans += (*ndj<2);
            *(infj)^=mask;
         }
      }

      printf("Case %d: %d\n", eset, ans);
   }

   return 0;
}

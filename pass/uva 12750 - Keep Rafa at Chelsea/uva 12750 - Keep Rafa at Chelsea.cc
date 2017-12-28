// type // administration // easy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   char res[512];

   int esetek;
   scanf("%d", &esetek);
   for(int eset=1; eset<=esetek; eset++){
      int n;
      scanf("%d", &n);
      int i = 0;
      while(i < n){
         int c = getchar();
         if(c == 'W'){
            res[i++] = 1;
            continue;
         }
         if(c=='L' || c=='D'){
            res[i++] = 0;
            continue;
         }
      }
      int ans = 7; // 111, right shift and add the actual result
      i = 0;
      while((i < n) && ans){
         ans /= 2;
         if(res[i]){
            ans += 4;
         }
         i++;
      }

      if(ans){
         printf("Case %d: Yay! Mighty Rafa persists!\n", eset);
      }else{
         printf("Case %d: %d\n", eset, i);
      }
   }

   return 0;
}

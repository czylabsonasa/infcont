// type // simple parsing
// switch-el bonyolultabb min if+function
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   auto getMass = [](char e){
      if('C'==e){
         return 12.01;
      }
      if('H'==e){
         return 1.008;
      }
      if('O'==e){
         return 16.00;
      }
      if('N'==e){
         return 14.01;
      }
      return 0.0;
   };

   char mol[512];
   int esetek;scanf("%d", &esetek);
   while(esetek--){
      scanf("%s", mol);
      double ans = 0.0;
      double m = 0;
      int num = 0;
      int idx = 0;
      char c;
      while((c = mol[idx])){
         if('0'<=c && c<='9'){
            num=10*num+(c-'0');
         }else{
            ans = ans+(num>0?num:1)*m;
            num = 0;
            m = getMass(c);;
         }
         idx++;
      }
      ans=ans+(num>0?num:1)*m;
      printf("%.3lf\n",ans);
   }

   return 0;
}

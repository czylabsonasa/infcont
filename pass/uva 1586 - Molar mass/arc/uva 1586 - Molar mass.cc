// type // simple parsing
// switch-el bonyolultabb min if+function
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   char mol[512];
   int esetek;scanf("%d", &esetek);
   while(esetek--){
      scanf("%s", mol);
      double ans=0.0;
      double m=0;
      int num=0;
      int idx=0;
      while(mol[idx]){

         switch(mol[idx]){
            case('C'):{
               ans=ans+(num>0?num:1)*m;
               num=0;;
               m=12.01;
               break;
            }
            case('H'):{
               ans=ans+(num>0?num:1)*m;
               num=0;;
               m=1.008;
               break;
            }
            case('O'):{
               ans=ans+(num>0?num:1)*m;
               num=0;;
               m=16.0;
               break;
            }
            case('N'):{
               ans=ans+(num>0?num:1)*m;
               num=0;;
               m=14.01;
               break;
            }
            default:{
               num=10*num+mol[idx]-'0';
            }
         }
         idx++;
      }
      ans=ans+(num>0?num:1)*m;
      printf("%.3lf\n",ans);


   }

   return 0;
}

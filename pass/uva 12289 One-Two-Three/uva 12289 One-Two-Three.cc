// type // string
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   auto diff=[](const char*x,char*y,int nx){
      int ans=0;
      while(*x&&*y){
         ans+=(*x!=*y);
         ++x;++y;
      }
      while(*x){
         ++ans;
         ++x;
      }
      while(*y){
         ++ans;
         ++y;
      }
      if(ans<2){
         printf("%d\n",nx);
         return true;
      }
      return false;
   };

   int n;scanf("%d",&n);
   while(n--){
      char w[8];
      scanf("%s",w);
      diff("one",w,1)||diff("two",w,2)||diff("three",w,3);
   }


   return 0;
}

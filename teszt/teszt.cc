// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   char expr[128];
   int a,b,c;
   char op;
   int ans=0;
   while(1==scanf("%s",expr)){
      int ok=sscanf(expr,"%d%c%d=%d",&a,&op,&b,&c);
//printf("  %d\n",ok);
      while(4==ok){
         if(op=='+'){
            ans+=((a+b)==c);
            break;
         }
         if(op=='-'){
            ans+=((a-b)==c);
            break;
         }
         break;
      }
   }
   printf("%d\n",ans);



   return 0;
}

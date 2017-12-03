// type // brute force // divisibility
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   //typedef long long int LLI;
   int a,b,c,d,L;
   while(1){
      scanf("%d%d%d%d%d",&a,&b,&c,&d,&L);
      if(a==0&&b==0&&c==0&&d==0&&L==0){
         break;
      }
      if(a%d==0&&b%d==0&&c%d==0){
         printf("%d\n",L+1);
      }else{
         int fx=(c%d);
         int ans=(fx==0);
         for(int i=1;i<=L;i++){
            fx+=(a*(2*i-1)+b);
            fx=fx%d;
            ans+=(fx==0);
         }
         printf("%d\n",ans);
         
      }
      
   }

   return 0;
}

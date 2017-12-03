// type // numbers // horner // divisibility
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   char num[1024];
   while(1){
      scanf("%s",num);
      if(num[0]=='0'){
         break;
      }
      int rem=num[0]-'0';
      int i=1;
      while(num[i]){
         rem=(10*rem)+num[i]-'0';
         rem=rem%17;
         i++;
      }
      if(0==rem){
         printf("1\n");
      }else{
         printf("0\n");
      }

   }


   return 0;
}

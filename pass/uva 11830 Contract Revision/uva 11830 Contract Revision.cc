// type // implementation // string
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){

   char num[1024];
   int m;//missing
   while(1){
      scanf("%d%s",&m,num);
      if(0==m){
         break;
      }
      m+='0';
      char*p=num;
      for(int i=0;num[i];i++){
         if(num[i]!=m){
            *(p++)=num[i];
         }
      }
      if(p==num){//full of m
         *(p++)='0';
      }
      *(p++)=0;
      p=num;//leading zeroes
      while(*p=='0'){
         p++;
      }
      if(*p==0){
         --p;
      }

      printf("%s\n",p);
   }

   return 0;
}

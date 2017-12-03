// type // implementation // string
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
void rev(char*b,char*e){
   while(b<e){
      swap(*b,*e);
      ++b;--e;
   }
}
int main(){
   char word[128];
   while(1){
      int nog;scanf("%d",&nog);
      if(0==nog){
         break;
      }
      scanf("%s",word);
      char*b=word;
      int len=strlen(word);
      int nel=len/nog;
      if(nel>1){
         while(nog--){
            rev(b,b+nel-1);
            b+=nel;
         }
      }
      printf("%s\n",word);
   }


   return 0;
}

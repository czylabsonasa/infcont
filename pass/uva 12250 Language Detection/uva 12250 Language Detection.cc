// type // search
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int main(){
   char szia[][16]={
      "HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"
   };
   char lang[][16]={
      "ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN"
   };
   char w[512];


   int eset=0;
   while(1){
      scanf("%s",w);
      if(w[0]=='#'){
         break;
      }
      int idx=0;
      while(idx<6&&strcmp(w,szia[idx])){
         idx++;
      }
      printf("Case %d: ",++eset);
      if(idx<6){
         printf("%s\n",lang[idx]);
      }else{
         printf("UNKNOWN\n");
      }
   }

   return 0;
}

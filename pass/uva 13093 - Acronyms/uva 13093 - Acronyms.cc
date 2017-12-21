// type // text parsing
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int const B=32*1024;
char buff[B+16];
char lista[32];
int main(){
   while(1){
      char*p=buff;*p=0;
      fgets(p,B,stdin);
      int nl=0;
      
      while(1){//first row
         while(*p&&!(*p>='a'&&*p<='z')){++p;}
         if(0==*p){
            break;
         }
         lista[nl++]=*(p++);
         while(*p&&(*p>='a'&&*p<='z')){++p;}
      }
//~ printf("----\n%d\n",nl);lista[nl]=0;
//~ printf("%s\n",lista);
      if(0==nl){
         break;
      }
      fgets(p=buff,B,stdin);//second row
      int found=0;
      while(found<nl){
         while(*p&&!(*p>='a'&&*p<='z')){++p;}
         if(0==*p){
            break;
         }
         if(*p==lista[found]){
            found++;
         }
         ++p;
         while(*p&&(*p>='a'&&*p<='z')){++p;}
      }
      if(found==nl){
         printf("yes\n");
      }else{
         printf("no\n");
      }
   }//esetek

   return 0;
}

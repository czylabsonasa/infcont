// type // simple // read the input
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   auto read5=[](char* x){
      int i=0;
      while(i<5){
         int c;
         while(!((c=getchar())==EOF)&&!(c=='0'||c=='1'));
         if(c==EOF){
            break;
         }
         x[i]=c-'0';
         i++;
      }
//printf("%d\n",i);
      return i;
   };

   char x1[16],x2[16];
   while(1){
      if(read5(x1)<5){
         break;
      }
      read5(x2);
      bool comp=true;
      for(int i=0;i<5;i++){
         if(x1[i]+x2[i]!=1){
            comp=false;
            break;
         }
      }
      if(comp){
         printf("Y\n");
      }else{
         printf("N\n");
      }
   }

   return 0;
}

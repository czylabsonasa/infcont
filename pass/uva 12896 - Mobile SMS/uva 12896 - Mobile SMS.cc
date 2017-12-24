// type // administration // simple
// handling the 0 keypresses not clear
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   char keyb[10][8]={
      "    ",     //0
      ".,?\"",    //1
      "abca",     //2
      "defd",     //3
      "ghig",     //4
      "jklj",     //5
      "mnom",     //6
      "pqrs",     //7
      "tuvt",     //8
      "wxyz"      //9
   };
   char msg[1024];
   int tipe[128],frek[128];
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int L;scanf("%d",&L);
      for(int i=0;i<L;i++){
         scanf("%d",&tipe[i]);
      }
      for(int i=0;i<L;i++){
         scanf("%d",&frek[i]);
      }
      int nmsg=0;
      for(int i=0;i<L;i++){
         int t=tipe[i];
         int f=frek[i];
         if(t){
            msg[nmsg++]=keyb[t][f-1];
         }else{//each press results a ' '
            while(f){
               msg[nmsg++]=' ';
               --f;
            }
         }
      }

      msg[nmsg]=0;
      printf("%s\n",msg);


   }

   return 0;
}

// type // simulation // stack
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
char lista[10008][20];
int main(){
   char cmd[20];
   int nq;scanf("%d",&nq);
   int nl=0;
   while(nq--){
      scanf("%s",cmd);
      while(1){
         if(!strcmp(cmd,"Sleep")){
            scanf("%s",lista[nl++]);
            break;
         }
         if(!strcmp(cmd,"Kick")){
            if(nl){
               --nl;
            }
            break;
         }
         if(!strcmp(cmd,"Test")){
            if(!nl){
               printf("Not in a dream\n");
            }else{
               printf("%s\n",lista[nl-1]);
            }
            break;
         }
      }//process
   }//nq
   return 0;
}

// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char site[10][128];
int rel[10];
int main(){
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int mx=-1;
      for(int i=0;i<10;i++){
         scanf("%s%d",site[i],&rel[i]);
         if(rel[i]>mx){
            mx=rel[i];
         }
      }


      printf("Case #%d:\n",eset);
      for(int i=0;i<10;i++){
         if(rel[i]==mx){
            printf("%s\n",site[i]);
         }
      }

   }

   return 0;
}

// type // administration
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char lista[1024][16];
int main(){
   auto check=[](char* x,char* y){
      int err=0;
      while(*x&&*y&&err<2){
         err+=(*x!=*y);
         ++x;++y;
      }
      return err<2&&(*x==*y);
   };
   
   char target[16];
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int nlist;scanf("%d",&nlist);
      for(int i=0;i<nlist;i++){
         scanf("%s",lista[i]);
      }
      scanf("%s",target);
      
      printf("Case %d:\n",eset);
      for(int i=0;i<nlist;i++){
         if(check(lista[i],target)){
            printf("%s\n",lista[i]);
         }
      }
   }

   return 0;
}

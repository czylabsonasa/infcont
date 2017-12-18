// type // easy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int z=0;
      for(int i=0;i<13;i++){
         int t;scanf("%d",&t);
         z+=(t==0);
      }

      printf("Set #%d: %s\n",eset,(z>0)?"No":"Yes");
   }

   return 0;
}

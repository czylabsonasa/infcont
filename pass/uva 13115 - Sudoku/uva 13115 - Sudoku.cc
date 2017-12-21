// type // administration
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int const N=25;
char sor[N][N],oszlop[N][N],kicsi[N][N];
int main(){
   int esetek;scanf("%d",&esetek);
   while(esetek--){
      int n2;scanf("%d",&n2);
      int n=1;while(n*n<n2){++n;}
      for(int i=0;i<n2;i++){
         for(int j=0;j<n2;j++){
            sor[i][j]=oszlop[i][j]=kicsi[i][j]=0;

         }
      }
      bool ok=true;
      int x=0,y=0;
      int it=0;
      int n4=n2*n2;
      while(it<n4&&ok){
         int t;scanf("%d",&t);--t;
         if(sor[x][t]||oszlop[y][t]||
         kicsi[n*(x/n)+(y/n)][t]){
            ok=false;
         }
         sor[x][t]=1;
         oszlop[y][t]=1;
         kicsi[n*(x/n)+(y/n)][t]=1;
         ++it;
         ++y;
         if(y==n2){
            ++x;y=0;
         }
      }
      while(it<n4){
         int t;scanf("%d",&t);
         ++it;
      }
      if(ok){
         printf("yes\n");
      }else{
         printf("no\n");
      }
   }

   return 0;
}

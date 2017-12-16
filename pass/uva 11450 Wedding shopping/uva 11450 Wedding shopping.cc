// type // coin change // administration
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int const G=32;
vector<int> gar[G];
int const R=256;
char reach[R];
int main(){
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int M,ngar;scanf("%d%d",&M,&ngar);
      for(int i=1;i<=ngar;i++){
         int ni;scanf("%d",&ni);
         gar[i].resize(ni);
         for(int j=0;j<ni;j++){
            scanf("%d",&gar[i][j]);
         }
      }
      int m=0;
      for(int i=1;i<=ngar;i++){
         sort(gar[i].begin(),gar[i].end());
         m+=gar[i][0];
      }
      if(m<=M){
         for(int i=0;i<=M;i++){
            reach[i]=0;
         }
         //level 1
         for(auto it=gar[1].begin();it!=gar[1].end()&&*it<=M;it++){
            reach[*it]=1;
         }
         //level >1
         for(int i=2;i<=ngar;i++){
            for(int j=M-gar[i][0];j>0;j--){
               if(reach[j]!=i-1){
                  continue;
               }
               for(auto it=gar[i].begin();it!=gar[i].end()&&(*it+j)<=M;it++){
                  reach[*it+j]=i;
               }
            }
         }
         m=M;
         while(reach[m]!=ngar){
            --m;
         }
      }


      if(m<=M){
         printf("%d\n",m);
      }else{
         printf("no solution\n");
      }
   }

   return 0;
}

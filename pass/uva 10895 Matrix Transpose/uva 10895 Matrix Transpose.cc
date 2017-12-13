// type // array/vector manipulation
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int const N=10008;
vector<vector<int>> loc(N),val(N);
int tloc[N],tval[N];
int main(){
   auto kiir=[](vector<int>& v,int nv){
      if(nv){
         printf("%d",v[0]);
         for(int j=1;j<nv;j++){
            printf(" %d",v[j]);
         }
      }
      printf("\n");
   };

   int m,n;
   while(2==scanf("%d%d",&m,&n)){
      for(int i=1;i<=m;i++){
         int nr;scanf("%d",&nr);
         for(int j=0;j<nr;j++){
            scanf("%d",&tloc[j]);
         }
         for(int j=0;j<nr;j++){
            scanf("%d",&tval[j]);
         }
         for(int j=0;j<nr;j++){
            loc[tloc[j]].push_back(i);
            val[tloc[j]].push_back(tval[j]);
         }
      }
      printf("%d %d\n",n,m);
      for(int i=1;i<=n;i++){
         int ni=loc[i].size();
         printf("%d%s",ni,(ni?" ":""));
         kiir(loc[i],ni);
         kiir(val[i],ni);
         loc[i].clear();
         val[i].clear();
      }

   }

   return 0;
}

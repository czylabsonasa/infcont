// type // administration
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
char solved[16*1024]={0};
vector<vector<int>> lista(3);
int main(){
   auto olvas=[](int const i){
      lista[i].clear();
      char mask=(1<<i);
      int mx=0;
      int n;scanf("%d",&n);
      while(n--){
         int t;scanf("%d",&t);
         solved[t]|=mask;
         mx=max(t,mx);
      }
      return mx;
   };
   auto ir=[](int const i,int mx){
      if(lista[i].size()<mx){return;}
      printf("%d %d",i+1,mx);
      for(int j=0;j<mx;j++){
         printf(" %d",lista[i][j]);
      }
      printf("\n");
   };
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int mx;
      mx=olvas(0);
      mx=max(mx,olvas(1));
      mx=max(mx,olvas(2));
      lista[0].clear();
      lista[1].clear();
      lista[2].clear();
      for(int i=1;i<=mx;i++){
         int s=solved[i];
         solved[i]=0;

         if(1==s){
            lista[0].push_back(i);
            continue;
         }
         if(2==s){
            lista[1].push_back(i);
            continue;
         }
         if(4==s){
            lista[2].push_back(i);
            continue;
         }
      }
      mx=lista[0].size();
      mx=max(mx,int(lista[1].size()));
      mx=max(mx,int(lista[2].size()));

      printf("Case #%d:\n",eset);
      ir(0,mx);
      ir(1,mx);
      ir(2,mx);
   }



   return 0;
}

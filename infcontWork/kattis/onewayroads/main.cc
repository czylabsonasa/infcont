// type //
// no bridge


#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define V 55
#define E V*V
int pre[V]={0},low[V]={0};
int ans[E][2],nans;
vector<vector<int>> g(V);

int ok;
int num;
void gen(int s,int par){
   int mini=pre[s]=++num;//itt jo novelni
   auto& gs=g[s];
   int ch=0;
   for(int j=0;j<gs.size()&&ok;j++){
      int t=gs[j];
      if(t==par||pre[t]>pre[s]){//szulo vagy már back-kent szamolva
         continue;
      }
      if(pre[t]>0){//back
         mini=min(mini,pre[t]);
      }else{
         ++ch;
         gen(t,s);
         if(low[t]>pre[s]){
            ok=0;
            break;
         }
         mini=min(mini,low[t]);

      }
      ans[nans][0]=s;
      ans[nans][1]=t;
      nans++;
   }

   low[s]=mini;
}


int main(){
   int v,e;scanf("%d%d",&v,&e);
   for(int i=1;i<=v;i++){
      g[i].clear();
   }
   for(int i=0;i<e;i++){
      int a,b;scanf("%d%d",&a,&b);
      g[a].push_back(b);
      g[b].push_back(a);
   }
   ok=1;
   num=0;
   nans=0;
   gen(1,-1);
   if(1==ok){
      printf("YES\n");
      for(int i=0;i<nans;i++){
         printf("%d %d\n",ans[i][0],ans[i][1]);
      }
   }else{
      printf("NO\n");
   }




   return 0;
}

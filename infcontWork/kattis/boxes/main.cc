// type //
// graf dfs rendezes
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define N 200008 //100008 volt
struct xx{
   int a,b;
   bool operator<(const xx& masik) const{
      return a<masik.a;
   }
};
xx info[N];
vector<vector<int>> g;
int ord;
void gen(int s){
   info[s].a=++ord;//itt jo novelni
   auto& gs=g[s];
   for(int j=0;j<gs.size();j++){
      gen(gs[j]);
   }
   info[s].b=ord;
}

int main(){
   int n;scanf("%d",&n);
   g.resize(n+1);
   for(int i=1;i<=n;i++){
      g[i].clear();
   }
   for(int i=1;i<=n;i++){
      int p;scanf("%d",&p);
      if(p){
         g[p].push_back(i);
      }
   }
   //~ for(int i=1;i<=n;i++){
      //~ printf("%d(%d):",i,g[i].size());
      //~ for(int j=0;j<g[i].size();j++){
         //~ printf(" %d",g[i][j]);
      //~ }
      //~ printf("\n");
   //~ }
   for(int i=1;i<=n;i++){
      info[i].a=0;;
   }
   ord=0;
   for( int i=1;i<=n;i++){
      if(0==info[i].a){
         gen(i);
      }
   }
   //~ for(int i=1;i<=n;i++){
      //~ printf("%d:",i);
      //~ printf("(%d,%d)\n",get<0>(info[i]),get<1>(info[i]));
   //~ }

   vector<xx> work;
   int q;scanf("%d",&q);
   while(q--){
      int m;scanf("%d",&m);
      work.resize(m);
      for(int i=0;i<m;i++){
         int t;scanf("%d",&t);
         work[i]=info[t];
      }
      sort(work.begin(),work.end());
      int ans=0;
      int p=-1;
      for(int i=0;i<m;i++){
         if(work[i].b>p){//new "root"
            ans+=(work[i].b-work[i].a+1);
            p=work[i].b;
         }
      }
      printf("%d\n",ans);
   }


   return 0;
}

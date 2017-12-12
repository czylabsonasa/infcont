// type // topological sort // bfs // graph
// set helyett lehetne priority_queue
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
int const D=128;
char drink[D][64];
struct data{
   char* name;
   int idx;
};
data adat[D],adatw[D];
int deg[D];
vector<vector<int>>adj(D);

int main(){
   set<int> myset;

   auto lex=[](const data& a,const data& b){
      return strcmp(a.name,b.name)<0;
   };

   int eset=0;
   int na;
   while(1==scanf("%d",&na)){
      //read+init
      adj.resize(na);
      for(int i=0;i<na;i++){
         scanf("%s",drink[i]);
         adat[i].name=drink[i];
         adat[i].idx=i;//original
         adatw[i]=adat[i];
         deg[i]=0;
         adj[i].clear();
      }
      sort(adatw,adatw+na,lex);

      char a[D],b[D];
      int nrel;
      scanf("%d",&nrel);
      data tmp;
      for(int i=0;i<nrel;i++){
         scanf("%s%s",a,b);
         tmp.name=a;
         auto ai=lower_bound(adatw,adatw+na,tmp,lex);
         tmp.name=b;
         auto bi=lower_bound(adatw,adatw+na,tmp,lex);
         adj[ai->idx].push_back(bi->idx);
         ++deg[bi->idx];
      }
      printf("Case #%d: Dilbert should drink beverages in this order:",++eset);
      myset.clear();
      for(int i=0;i<na;i++){
         if(0==deg[i]){
            myset.insert(i);
         }
      }
      for(int i=0;i<na;i++){
         auto s=myset.begin();
         int is=*s;
         printf(" %s",adat[is].name);
         myset.erase(s);
         for(auto it=adj[is].begin();it!=adj[is].end();it++){
            if(--deg[*it]==0){
               myset.insert(*it);
            }
         }
      }
      printf(".\n\n");

   }
   return 0;
}

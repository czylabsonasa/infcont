// type // topological sort // bfs // graph
// wa
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int const D=128;
char drink[D][64];
struct data{
   char* name;
   int idx;
   int dist;
};

bool less1(const data& a,const data& b){
   return strcmp(a.name,b.name)<0;
}
bool less2(const data& a,const data& b){
   return (a.dist<b.dist)||((a.dist==b.dist)&&(a.idx<b.idx));
}

data adat[D];
vector<vector<int>> adj(D);
int indeg[D];
int queue[D];

int main(){

   int eset=0;
   int na;
   while(1==scanf("%d",&na)){
      //read+init
      for(int i=0;i<na;i++){
         scanf("%s",drink[i]);
         adat[i].name=drink[i];
         adat[i].idx=i;
         adj[i].clear();
         indeg[i]=0;
      }
      sort(adat,adat+na,less1);
      int nrel;
      data tmp;
      scanf("%d",&nrel);
      for(int i=0;i<nrel;i++){
         char a[D],b[D];
         scanf("%s%s",a,b);
         tmp.name=a;
         int ai=lower_bound(adat,adat+na,tmp,less1)-adat;
         tmp.name=b;
         int bi=lower_bound(adat,adat+na,tmp,less1)-adat;
         adj[ai].push_back(bi);
         ++indeg[bi];
      }

      int head=0,tail=0;
      for(int i=0;i<na;i++){
         if(0==indeg[i]){
            queue[tail++]=i;
            adat[i].dist=0;
         }
      }
      while(head!=tail){
         int s=queue[head++];
         int dist=adat[s].dist+1;
//printf("   %s %d\n",adat[s].name,)
         for(auto it=adj[s].begin();it!=adj[s].end();it++){
            if(--indeg[*it]==0){
               queue[tail++]=*it;
               adat[*it].dist=dist;
            }
         }
      }
      sort(adat,adat+na,less2);

      printf("Case #%d: Dilbert should drink beverages in this order:",++eset);
      for(int i=0;i<na;i++){
         printf(" %s",adat[i].name);
      }
      printf(".\n\n");

   }

   return 0;
}

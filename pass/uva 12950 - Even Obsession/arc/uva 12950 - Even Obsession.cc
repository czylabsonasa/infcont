// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int const INF=2000000000; //5*10^4 * 10^4
int const NV=10008;
int dist[2][NV];

struct mpar{
   int s,w;
};
vector<vector<mpar>> graph;

int main(){
   auto myless = [](const mpar& a, const mpar& b)->bool{
      return dist[a.s] > dist[b.s];
   };

   int nv, ne;
   while(2 == scanf("%d%d", &nv, &ne)){
      graph.resize(nv+1);
      for(int i=0; i<=nv; i++){
         graph[i].clear();
      }
      for(int i=0; i<ne; i++){
         int a, b, w;
         scanf("%d%d%d", &a, &b, &w);
         graph[a].push_back(mpar{b,w});
         graph[b].push_back(mpar{a,w});
      }
      priority_queue<mpar, vector<mpar>, decltype(myless)> pq(myless);
      for(int i=1; i<=nv; i++){
         dist[0][i] = dist[1][i] = INF;
      }
      dist[0][1] = 0;
      pq.push(mpar{1,0});
      while(!pq.empty()){
         auto tmp=pq.top();
         int s = tmp.s;
         int tip = tmp.w;
         pq.pop();
         if(s==nv && 0==tip){//!!!
            break;
         }
         int d = dist[tip][s];
         tip = 1-tip;
         for(auto tmp: graph[s]){
            int t = tmp.s;
            int w = tmp.w;
            if(d+w < dist[tip][t]){
               dist[tip][t] = d+w;
               pq.push(mpar{t, tip});
            }
         }
      }//Dijkstra
      if(dist[0][nv] >= INF){
         printf("-1\n");
      }else{
         printf("%d\n", dist[0][nv]);
      }
   }

   return 0;
}

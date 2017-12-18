// type // graph // bfs // 0-1 bfs
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cassert>
#include <deque>

using namespace std;

int main(){
   int const INF=1000000000;
   int nv,ne;scanf("%d%d",&nv,&ne);
   vector<vector<int>> graph(nv+1);

   for(int i=0;i<ne;i++){
      int a,b;scanf("%d%d",&a,&b);
      if(a!=b){
         graph[a].push_back(b);
         graph[b].push_back(-a);
      }
   }

   vector<int> dist(nv+1,INF);
   deque<int> ks;
   ks.push_front(1);
   dist[1]=0;

   while(!ks.empty()){
      int s=ks.front();
      if(nv==s){
         break;
      }
      ks.pop_front();
      int ds=dist[s];

      for(int t:graph[s]){
         if(t>0){
            if(ds<dist[t]){
               dist[t]=ds;
               ks.push_front(t);
            }
         }else{
            t=(-t);
            if(ds+1<dist[t]){
               dist[t]=ds+1;
               ks.push_back(t);
            }
         }
      }
   }

   if(dist[nv]>=INF){
      printf("-1\n");
   }else{
      printf("%d\n",dist[nv]);
   }

   return 0;
}

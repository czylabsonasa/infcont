// type // graph // bfs // 0-1 bfs
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cassert>
#include <deque>
#include <iostream>

using namespace std;

int main(){
   int const INF=1000000000;
   int nv,ne;scanf("%d%d",&nv,&ne);
   vector<vector<int>> graph0(nv+1),graph1(nv+1);

   vector<int> dist(nv+1,INF);
   for(int i=0;i<ne;i++){
      int a,b;scanf("%d%d",&a,&b);
      if(a!=b){
         graph0[a].push_back(b);
         graph1[b].push_back(a);
      }
   }

   deque<int> ks;
   ks.push_front(1);
   dist[1]=0;

   while(!ks.empty()){
      int s=ks.front();
      ks.pop_front();
      int ds=dist[s];

      for(int t:graph0[s]){
         if(dist[t]<INF){continue;}
         dist[t]=ds;
         ks.push_front(t);
      }
      ++ds;
      for(int t:graph0[s]){
         if(dist[t]<INF){continue;}
         dist[t]=ds;
         ks.push_back(t);
      }
   }

   if(dist[nv]>=INF){
      printf("-1\n");
   }else{
      printf("%d\n",dist[nv]);
   }

   return 0;
}

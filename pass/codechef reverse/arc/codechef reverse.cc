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
   vector<vector<int>> graph(nv+1);
   for(int i=0;i<=nv;i++){
      graph[i].clear();
   }
//printf("%d",graph.size())   ;
   vector<int> dist(nv+1,INF);
   for(int i=0;i<ne;i++){
      int a,b;scanf("%d%d",&a,&b);
      if(a!=b){
         graph[a].push_back(b);
         graph[b].push_back(-a);
      }
   }

   for(int i=0;i<=nv;++i) {
      sort(graph[i].begin(), graph[i].end(), greater<int>());
    /*  cerr<<i<<": ";
      for(auto j:graph[i]) {
         cerr<<j<<" ";
      }cerr<<"\n";*/
   }
   deque<int> ks;
   ks.push_front(1);
   dist[1]=0;



   while(!ks.empty()){
      int s=ks.front();

      //cerr<<s<<"\n";

      ks.pop_front();
      int ds=dist[s];
      //for(int t:graph[s]){
      for(auto it=graph[s].begin();it!=graph[s].end();it++){
         int t=*it;

         //cerr<<t<<"!!\n";
         if(t>0){
            //if(dist[t]<INF){continue;}
            if(dist[t]>ds) {
               dist[t]=ds;

               ks.push_front(t);
            }
         }else{
            t=(-t);
            //cerr<<s<<"->"<<t<<" "<<ds<<" "<<dist[t]<<"\n";

            //if(dist[t]<INF){ continue;}
            if(dist[t]>ds+1) {

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

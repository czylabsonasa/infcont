// type // graph // diameter // brute-force
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int const V=64;
char lista[V][256];
int const INF=V*V;



int main(){
   int dist[V], q[V];
   vector<vector<int>> graph(V);

   auto search=[](char* p){
      int f=0;
      while(strcmp(lista[f],p)){
         ++f;
      }
      return f;
   };

   int eset=1;
   while(1){
      int nv, ne;
      scanf("%d%d", &nv, &ne);
      if(0==nv+ne){
         break;
      }
      for(int i=0; i<nv; i++){
         graph[i].clear();
      }

      int ans=0;
      while(ne){
         int tnv=0;
         for(int i=0; i<ne; i++){
            scanf("%s",lista[tnv]);
            int a=search(lista[tnv]);
            if(a>=tnv){
               ++tnv;
            }
            scanf("%s",lista[tnv]);
            int b=search(lista[tnv]);
            if(b>=tnv){
               ++tnv;
            }
//~ printf("%d %s\n", a, lista[a]);
//~ printf("%d %s\n", b, lista[b]);
            graph[a].push_back(b);
            graph[b].push_back(a);
         }
         if(tnv<nv){//degree 0 vertex
            break;
         }

         for(int i=0; i<nv; i++){
            fill(dist, dist+nv, INF);
            int head=0, tail=1;
            dist[i]=0;
            q[0]=i;
            while(head!=tail){
               int s=q[head++];
               int d=dist[s]+1;
               for(auto t:graph[s]){
                  if(d<dist[t]){
                     dist[t]=d;
                     q[tail++]=t;
                  }
               }
            }
            if(tail<nv){//eleg lenne 1x
               break;
            }
            ans=max(ans, dist[nv-1]);
         }
         break;
      }

      if(ans){
         printf("Network %d: %d\n\n", eset, ans);
      }else{
         printf("Network %d: DISCONNECTED\n\n", eset);
      }
      ++eset;
   }

   return 0;
}

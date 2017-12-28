// type // graph //
// "wrong" solution, see myless vs. dist
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>//pair
using namespace std;
#define GETCHAR getchar_unlocked
bool getNum(int&x){
   int i;
   while(!(((i=GETCHAR())>='0')&&(i<='9'))&&i!=EOF);
   if(i==EOF){
      return false;
   }
   x=(i-'0');
   while(((i=GETCHAR())>='0')&&(i<='9')){
      x=((x<<1)+(x<<3)+(i-'0'));
   }
   return true;
}

int const INF=2000000000; //5*10^4 * 10^4
int const NV=10008;
int dist[2*NV];
typedef pair<int,int> mpar;
#define NODE first
#define WEIGHT second

int main(){
   auto myless = [](int a, int b)->bool{
      return dist[a] > dist[b];
   };


   while(true){
      int nv, ne;
      if(!getNum(nv)){
         break;
      }
      getNum(ne);
//printf("nv:%d ne:%d\n", nv, ne);

      vector<vector<mpar>> graph;
      graph.resize(nv+1);
      for(int i=0; i<ne; i++){
         int a, b, w;
         getNum(a);
         getNum(b);
         getNum(w);
         graph[a].push_back(mpar{b,w});
         graph[b].push_back(mpar{a,w});
      }

      fill(dist, dist+2*nv+1, INF);

      dist[1] = 0;
      priority_queue<int, vector<int>, decltype(myless)> pq(myless);
      pq.push(1);
      while(!pq.empty()){
         int s=pq.top();
         pq.pop();
         int delta = nv;
         int rs = s;
         if(s>nv){
            rs = s-nv;
            delta = 0;
         }
         if(s==nv){
            break;
         }
         int d = dist[s];
//printf(" fej:%d %d\n", s, delta);
         for(auto tmp: graph[rs]){
            int t = tmp.NODE+delta;
            int w = tmp.WEIGHT;
//printf("  %d %d\n", t, w);

            if(d+w < dist[t]){
               dist[t] = d+w;
               pq.push(t);
//printf("*\n");
            }
         }
      }//Dijkstra
      if(dist[nv] >= INF){
         printf("-1\n");
      }else{
         printf("%d\n", dist[nv]);
      }
   }

   return 0;
}

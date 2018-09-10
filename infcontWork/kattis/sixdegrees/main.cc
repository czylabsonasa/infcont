// type //
// bfs egyszerusitesekkel, nem az osszes csucsbol
#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

typedef vector<vector<int>> graf;
typedef vector<int> arr;

int const INF=2*3000;
void bfs(graf& gr,int s, arr& q, arr& d){
   fill(d.begin(),d.end(),INF);
   d[s]=0;
   q[0]=s;
   int head=0, tail=1;
   while(head!=tail){
      s=q[head++];
      int t=1+d[s];
      auto& gs=gr[s];
      for(auto it=gs.begin();it!=gs.end();it++){
         if(t<d[*it]){
            d[*it]=t;
            q[tail++]=*it;
         }
      }
   }
}

void check(int const v,arr& q,arr& d, arr& jo, int& nbad){
   int md=d[q1[v-1]];
   if(md<4){//no bad mach
      nbad=-1;
      return;
   }
   if(md>12){//all mach is bad
      nbad=-2;
      return;
   }
   int i=0;
   while(i<v){
      int qi=q[i];
      if(d[qi]+7>md){
         break;
      }
      nbad+=jo[qi];
      jo[qi]=0;
      i++;
   }
   i=v-1;
   while(i>=0){
      int qi=q[i];
      if(d[qi]-7<0){
         break;
      }
      nbad+=jo[qi];
      jo[qi]=0;
      i--;
   }
}

int main(){
   ios::sync_with_stdio(false);
   unordered_map<string,int> dict;
   graf gr;
   vector<pair<string,string>> edges;
   arr q1,q2,d1,d2;
   arr jo;

   int esetek;cin>>esetek;
   while(esetek--){
      int e;cin>>e;
      edges.resize(e);
      for(int i=0;i<e;i++){//olvas
         cin>>edges[i].first>>edges[i].second;
      }

      dict.clear();
      int v=0;// 1 bazisu
      for(int i=0;i<e;i++){//dict
         string& a=edges[i].first;
         string& b=edges[i].second;
         auto pa=dict.find(a);
         if(pa==dict.end()){
            dict[a]=++v;
         }
         auto pb=dict.find(b);
         if(pb==dict.end()){
            dict[b]=++v;
         }
      }
      gr.resize(v+1);//graf
      for(int i=1;i<=v;i++){
         gr[i].clear();
      }
      for(int i=0;i<e;i++){
         int a=dict[edges[i].first];
         int b=dict[edges[i].second];
         gr[a].push_back(b);
         gr[b].push_back(a);
      }

      int lim=floor((v*5)/100.0)+1;

      q1.resize(v+1);
      d1.resize(v+1);
      q2.resize(v+1);
      d2.resize(v+1);
      jo.resize(v+1);
      fill(jo.begin(),jo.end(),1);

      bfs(gr,1,q1,d1);
      check(v,q1,d1,jo,nbad);

      int i=v-1;
      while(1){
         check(v,q1,d1,jo,nbad);
         if(nbad)
         int t=d1[q1[v-1]];
         if(t<4){//no bad mach
            break;
         }
         if(t>12){//all mach is bad
            ans=0;
            break;
         }
         int nbad=0;
      }




   }

   return 0;
}

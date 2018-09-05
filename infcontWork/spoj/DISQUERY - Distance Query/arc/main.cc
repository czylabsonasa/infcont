// type // graph // lca
#define MDEBUG(x)
//#define MASS( x ) assert(x)
#define MASS(x)

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <cassert>

using namespace std;
int const N=100008;
struct info3{
   int node;
   int mini;
   int maxi;
};
struct info2{
   int node;
   int w;
};


vector<vector<info2>> gr;
vector<vector<info3>> table;
vector<int> lev, par, path;

void pre(int node, int l, int prt, int w){
   path[l]=node;
   lev[node]=l; par[node]=prt;
   if(0!=l){
      table[node].push_back(info3{prt,w, w});
      for(int u=2,i=0; u<=l; u<<=1,++i){
         int mid=path[l-(u>>1)];
         int tmini=min(table[node][i].mini, table[mid][i].mini);
         int tmaxi=max(table[node][i].maxi, table[mid][i].maxi);
         table[node].push_back(info3{path[l-u], tmini, tmaxi});
      }
   }
   for(auto s:gr[node]){
      if(s.node!=prt){
         pre(s.node, l+1, node, s.w);
      }
   }
}

int const INF=1000000000;
int mini, maxi;
#define ADJ(_x,_i){\
   mini=min(mini, table[(_x)][(_i)].mini);\
   maxi=max(maxi, table[(_x)][(_i)].maxi);\
}
int up(int x, int k){//assumption there is a node up to k level
   int i=0;
   while(k){
      if(k&1){
         ADJ(x,i);
         //~ mini=min(mini, table[x][i].mini);
         //~ maxi=max(maxi, table[x][i].maxi);
         x=table[x][i].node;
      }
      k=k>>1;
      ++i;
   }
   return x;
}


int lca(int x, int y){
   if(lev[x]<lev[y]){
      swap(x, y);
   }

//cerr<<x<<" "<<y<<" cs\n";
   x=up(x, lev[x]-lev[y]);// equalize levels
//cerr<<mini<<" "<<maxi<< "mm\n";

   if(x==y){
      return x;
   }
   if(par[x]==par[y]){
      ADJ(x,0);
      ADJ(y,0);
   //~ mini=min(mini, table[x][0].mini);
   //~ maxi=max(maxi, table[x][0].maxi);
   //~ mini=min(mini, table[y][0].mini);
   //~ maxi=max(maxi, table[y][0].maxi);

      return par[x];
   }

   int i=table[x].size();
   while(par[x]!=par[y]){
      i=min(i-1,int(table[x].size()-1));
      while(table[x][i].node==table[y][i].node){
         --i;
      }

      ADJ(x,i);
      ADJ(y,i);
      //~ mini=min(mini, table[x][i].mini);
      //~ maxi=max(maxi, table[x][i].maxi);
      //~ mini=min(mini, table[y][i].mini);
      //~ maxi=max(maxi, table[y][i].maxi);

      x=table[x][i].node;
      y=table[y][i].node;
   }

   ADJ(x,0);
   ADJ(y,0);

   //~ mini=min(mini, table[x][0].mini);
   //~ maxi=max(maxi, table[x][0].maxi);
   //~ mini=min(mini, table[y][0].mini);
   //~ maxi=max(maxi, table[y][0].maxi);

   return par[x];
}




int main(){
   ios::sync_with_stdio(false);

   int n; cin>>n;
   gr.resize(n+1);
   table.resize(n+1);
   path.resize(n+1);
   par.resize(n+1);
   lev.resize(n+1);

   for(int i=1; i<n; i++){
      int a,b,w; cin>>a>>b>>w;
      gr[a].push_back(info2{b,w});
      gr[b].push_back(info2{a,w});
   }

   pre(1,0,1,0);//par[1]=1

   int nq; cin>>nq;
   for(int i=1; i<=nq; i++){
      int a, b; cin>>a>>b;
      mini=INF;
      maxi=-INF;
      lca(a,b);
      cout<<mini<<" "<<maxi<<"\n";
   }//queries

   return 0;
}

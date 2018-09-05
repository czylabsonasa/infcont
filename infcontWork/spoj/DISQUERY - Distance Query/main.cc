// rte valhol...

// type // graph // lca
#define MDEBUG(x)
//#define MASS( x ) assert(x)
#define MASS(x)

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <cassert>
using namespace std;

#define GETCHAR getchar_unlocked
int getNum(void){
   int i,ans;
   while(!(((i=GETCHAR())>='0')&&(i<='9')));
   ans=(i-'0');
   while(((i=GETCHAR())>='0')&&(i<='9')){
      ans=((ans<<1)+(ans<<3)+(i-'0'));
   }
   return ans;
}

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
vector<vector<info3>> table(20);
vector<int> lev, par, path, meret;

void pre(int node, int l, int prt, int w){
   path[l]=node;
   lev[node]=l; par[node]=prt;
   int mer=0;
   if(0!=l){
      table[0][node]=info3{prt,w, w};
      mer=1;
      for(int u=2,i=0; u<=l; u<<=1,++i){
         ++mer;
         int mid=path[l-(u>>1)];
         int tmini=min(table[i][node].mini, table[i][mid].mini);
         int tmaxi=max(table[i][node].maxi, table[i][mid].maxi);
         table[i+1][node]=info3{path[l-u], tmini, tmaxi};
      }
   }
   meret[node]=mer;

   for(auto s:gr[node]){
      if(s.node!=prt){
         pre(s.node, l+1, node, s.w);
      }
   }
}

int const INF=1000000000;
int mini, maxi;
#define ADJ(_x,_i){\
   mini=min(mini, table[(_i)][(_x)].mini);\
   maxi=max(maxi, table[(_i)][(_x)].maxi);\
}

int up(int x, int k){//assumption there is a node up to k level
   int i=0;
   while(k){
      if(k&1){
         ADJ(x,i);
         x=table[i][x].node;
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

   x=up(x, lev[x]-lev[y]);// equalize levels

   if(x==y){
      return x;
   }

   if(par[x]==par[y]){
      ADJ(x,0);
      ADJ(y,0);
      return par[x];
   }

   int i=meret[x];
   while(par[x]!=par[y]){
      i=min(i-1,int(meret[x]-1));
      while(table[i][x].node==table[i][y].node){
         --i;
      }

      ADJ(x,i);
      ADJ(y,i);
      x=table[i][x].node;
      y=table[i][y].node;
   }

   ADJ(x,0);
   ADJ(y,0);

   return par[x];
}


int main(){

   int n=getNum();
   gr.resize(n+1);
   {
      int l2n=1;
      while((l2n>>1)<=n){
         l2n<<=1;
      }
      for(int i=0; i<=l2n; i++){
         table[i].resize(n+1);
      }
   }

   path.resize(n+1);
   par.resize(n+1);
   lev.resize(n+1);
   meret.resize(n+1);

   for(int i=1; i<n; i++){
      int a=getNum();
      int b=getNum();
      int w=getNum();
      gr[a].push_back(info2{b,w});
      gr[b].push_back(info2{a,w});
   }

   pre(1,0,1,0);//par[1]=1

   int nq=getNum();
   for(int i=1; i<=nq; i++){
      int a=getNum();
      int b=getNum();
      mini=INF;
      maxi=-INF;
      lca(a, b);
      printf("%d %d\n", mini, maxi);
   }//queries

   return 0;
}

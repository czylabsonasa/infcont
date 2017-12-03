// type // search // disjoint set
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct disjointSet{
   int H;
   vector<int> holvan;
   disjointSet(int tH=1000):H(tH),holvan(H){}
   void clear(int aH){
      if(aH>H){
         H=aH;
         holvan.resize(H);
      }
      for(int i=0;i<aH;i++){
         holvan[i]=-1;
      }
   }
   int PH(int ez){ // utfelezeses (PathHalving)
      int h,hh;
      if((h=holvan[ez])){
         while((hh=holvan[h])){
            holvan[ez]=hh;
            ez=h;
            h=hh;
         }
         ez=h;
      }
      return ez;
   }
   int find(int t){ // tomoriteses (PathCompressing)
      int ht,ans;
      ans=ht=t;
      while((ht=holvan[ht])>=0){
         ans=ht ;
      }
      while((ht=holvan[t])>=0){
         holvan[t]=ans;
         t=ht;
      }
      return ans;
   }
   void unio(int a,int b){
      holvan[a]=b;
   }
};

struct data{
   int a,b,d;
   bool operator<(const data&masik)const{
      return d<masik.d;
   }
};
data adatok[1000008];

int main(){
   disjointSet ds(1000008);

   while(1){
      int v,e;scanf("%d%d",&v,&e);
      if(0==v+e){
         break;
      }
      ds.clear(v);
      for(int i=0;i<e;i++){
         scanf("%d%d%d",&adatok[i].a,&adatok[i].b,&adatok[i].d);
      }
      int ans=0;
      if(v>1){
         ans=-1;
         sort(adatok,adatok+e);
         int nc=v;
         for(int i=0;(i<e)&&(nc>1);i++){
            int a=ds.find(adatok[i].a);
            int b=ds.find(adatok[i].b);
            if(a!=b){
               ds.unio(a,b);
               if(1==(--nc)){
                  ans=adatok[i].d;
                  break;
               }
            }
         }
      }
      if(ans>=0){
         printf("%d\n",ans);
      }else{
         printf("IMPOSSIBLE\n");
      }
   }
   return 0;
}


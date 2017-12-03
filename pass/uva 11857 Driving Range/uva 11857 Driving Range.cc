// type // search // disjoint set
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define GETCHAR getchar_unlocked
int getnum(void){
   int i,ans;
   while(!(((i=GETCHAR())>='0')&&(i<='9'))&&(i!='-'));
   ans=(i-'0');
   while(((i=GETCHAR())>='0')&&(i<='9')){
      ans=((ans<<1)+(ans<<3)+(i-'0'));
   }
   return ans;
}

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
   int find(int t){ // utfelezeses (PathHalving)
      int ht,hht;
      if((ht=holvan[t])>=0){
         while((hht=holvan[ht])>=0){
            holvan[t]=hht;
            t=ht;
            ht=hht;
         }
         t=ht;
      }
      return t;
   }
   int find_(int t){ // tomoriteses (PathCompressing)
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
      int v=getnum();
      int e=getnum();
      if(0==v+e){
         break;
      }
      ds.clear(v);
      for(int i=0;i<e;i++){
         adatok[i].a=getnum();
         adatok[i].b=getnum();
         adatok[i].d=getnum();
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



// type //
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
   int find_(int t){ // utfelezeses (PathHalving)
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
      if(a!=b){
         holvan[a]=b;
      }
   }
};


int main(){
   disjointSet ds;
   vector<int> osszeg;
   vector<int> meret;
   vector<int> valodi;
   int n,m;
   while(2==scanf("%d%d",&n,&m)){
      ds.clear(n+m+9);
      osszeg.resize(n+m+9);
      meret.resize(n+m+9);
      valodi.resize(n+m+9);

      for(int i=0;i<=n;i++){
         osszeg[i]=i;
         meret[i]=1;
         valodi[i]=i;
      }
      int end=n;
      for(int i=0;i<m;i++){
         int t;scanf("%d",&t);
         switch(t){
            case(1):{
               int p,q;scanf("%d%d",&p,&q);
               if(p!=q){
                  p=ds.find(valodi[p]);
                  q=ds.find(valodi[q]);
                  ds.holvan[p]=q;
                  meret[q]+=meret[p];
                  osszeg[q]+=osszeg[p];
                  meret[p]=osszeg[p]=0;
               }
               break;
            }
            case(2):{
               int p,q;scanf("%d%d",&p,&q);
               if(p!=q){
                  int tp=ds.find(valodi[p]);
                  q=ds.find(valodi[q]);
                  ++end;
                  valodi[p]=end;
                  ds.holvan[end]=q;
                  meret[q]+=1;
                  osszeg[q]+=p;
                  meret[tp]-=1;
                  osszeg[tp]-=p;
               }
               break;
            }
            case(3):{
               int p;scanf("%d",&p);
               p=ds.find(valodi[p]);
               printf("%d %d\n",meret[p],osszeg[p]);
               break;
            }
         }
      }
   }

   return 0;
}

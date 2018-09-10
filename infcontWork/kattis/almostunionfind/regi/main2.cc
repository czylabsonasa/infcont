// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> parent(200022);
int find(int t){ // utfelezeses (PathHalving)
   int ht,hht;
   if((ht=parent[t])>=0){
      while((hht=parent[ht])>=0){
         parent[t]=hht;
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
   while((ht=parent[ht])>=0){
      ans=ht ;
   }
   while((ht=parent[t])>=0){
      parent[t]=ans;
      t=ht;
   }
   return ans;
}

int main(){
   vector<int> osszeg(100011);
   vector<int> meret(100011);
   vector<int> valodi(100011);
   int n,m;
   while(2==scanf("%d%d",&n,&m)){
      for(int i=0;i<=n;i++){
         osszeg[i]=i;
         meret[i]=1;
         valodi[i]=i;
         parent[i]=-1;
      }
      int end=n;
      for(int i=0;i<m;i++){
         int t;scanf("%d",&t);
         switch(t){
            case(1):{
               int p,q;scanf("%d%d",&p,&q);
               if(p!=q){
                  p=find(valodi[p]);
                  q=find(valodi[q]);
                  parent[p]=q;
                  meret[q]+=meret[p];
                  osszeg[q]+=osszeg[p];
                  meret[p]=osszeg[p]=0;
               }
               break;
            }
            case(2):{
               int p,q;scanf("%d%d",&p,&q);
               if(p!=q){
                  int tp=find(valodi[p]);
                  q=find(valodi[q]);
                  ++end;
                  valodi[p]=end;
                  parent[end]=q;
                  meret[q]+=1;
                  osszeg[q]+=p;
                  meret[tp]-=1;
                  osszeg[tp]-=p;
               }
               break;
            }
            case(3):{
               int p;scanf("%d",&p);
               p=find(valodi[p]);
               printf("%d %d\n",meret[p],osszeg[p]);
               break;
            }
         }
      }
   }

   return 0;
}

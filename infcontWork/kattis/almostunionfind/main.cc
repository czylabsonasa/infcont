// type //
#include <cstdio>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


long long int osszeg[100011];
int meret[100011];
int valodi[100011];


int parent[200022];
int find(int t){
   return parent[t]>=0?parent[t]=find(parent[t]):t;
}

//~ int find(int t){ // utfelezeses (PathHalving)
   //~ int pt,ppt;
   //~ if((pt=parent[t])>=0){
      //~ while((ppt=parent[pt])>=0){
         //~ parent[t]=ppt;
         //~ t=pt;
         //~ pt=ppt;
      //~ }
      //~ t=pt;
   //~ }
   //~ return t;
//~ }

//~ int find(int t){ // tomoriteses (PathCompressing)
   //~ int pt,ans;
   //~ ans=pt=t;
   //~ while((pt=parent[pt])>=0){
      //~ ans=pt ;
   //~ }
   //~ while((pt=parent[t])>=0){
      //~ parent[t]=ans;
      //~ t=pt;
   //~ }
   //~ return ans;
//~ }

int main(){
   int n,m;
   while(2==scanf("%d%d",&n,&m)){
//assert(n<=100000&&m<=100000);

//printf("----------\n");
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
            case(1):{//unio
               int p,q;scanf("%d%d",&p,&q);
               p=find(valodi[p]);
               q=find(valodi[q]);
               if(p!=q){
//assert(1<=p&&p<=n&&1<=q&&q<=n);
                  parent[p]=q;
                  meret[q]+=meret[p];
                  osszeg[q]+=osszeg[p];
                  meret[p]=osszeg[p]=0;
               }
               break;
            }
            case(2):{//move
               int p,q;scanf("%d%d",&p,&q);
               int tp=find(valodi[p]);
               q=find(valodi[q]);
               if(tp!=q){
//assert(1<=p&&p<=n&&1<=q&&q<=n);
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
//assert(1<=p&&p<=n);
               p=find(valodi[p]);
               printf("%d %lld\n",meret[p],osszeg[p]);
               break;
            }
         }
      }
   }

   return 0;
}

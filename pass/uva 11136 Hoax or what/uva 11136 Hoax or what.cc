// tag // implementation // searching // data structure
// todo // too slow
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;
int inset[1000000+11]={0};
int main(){
   set<int> tarolo;
   while(1){
      int nod;scanf("%d",&nod);//no of days
      if(0==nod){
         break;
      }
      long long int ans=0;//wa volt mert 5000*(10^6-1)>int32
      for(int d=1;d<=nod;d++){
         int k;scanf("%d",&k);
         while(k--){
            int t;scanf("%d",&t);
            if(0==inset[t]){
               tarolo.insert(t);
            }
            ++inset[t];
         }
         auto a=tarolo.begin();
         auto b=(tarolo.end());--b;
         ans+=(*b-*a);
         assert(a!=b);
         --inset[*a];
         --inset[*b];
         tarolo.erase(a);
         tarolo.erase(b);
      }

      printf("%lld\n",ans);

      //~ for(auto it=tarolo.begin();it!=tarolo.end();it++){
         //~ inset[*it]=0;
      //~ }
      //~ if(tarolo.size()>0)tarolo.clear();


   }

   return 0;
}

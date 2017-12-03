// tag // implementation / searching / data structure
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
int main(){
   multiset<int> tarolo;
   while(1){
      int nod;scanf("%d",&nod);//no of days
      if(0==nod){
         break;
      }
      long long int ans=0;//wa volt mert 5000*(10^6-1)>int32
      tarolo.clear();
      for(int d=1;d<=nod;d++){
         int k;scanf("%d",&k);
         while(k--){
            int t;scanf("%d",&t);
            tarolo.insert(t);
         }
         auto a=tarolo.begin();
         auto b=(tarolo.end());--b;
         ans+=(*b-*a);
         tarolo.erase(a);
         tarolo.erase(b);
      }

      printf("%lld\n",ans);
   }

   return 0;
}

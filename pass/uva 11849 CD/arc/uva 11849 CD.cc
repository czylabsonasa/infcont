// type // set intersection // sort // merge
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
int main(){
   set<int> a;
   while(1){
      int na,nb;
      scanf("%d%d",&na,&nb);
      if(na+nb==0){
         break;
      }
      a.clear();
      for(int i=0;i<na;i++){
         int t;scanf("%d",&t);
         a.insert(t);
      }
      int ans=0;
      for(int i=0;i<nb;i++){
         int t;scanf("%d",&t);
//         auto loc=lower_bound(a.begin(),a.end(),t); TLE,it not log
         auto loc=a.lower_bound(t);
         if((loc!=a.end()) && (*loc==t)){
            ++ans;
         }
      }
      printf("%d\n",ans);
   }

   return 0;
}

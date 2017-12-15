// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int n;scanf("%d",&n);
      int mx;
      scanf("%d",&mx);
      for(int i=1;i<n;i++){
         int t;
         scanf("%d",&t);
         if(t>mx){
            mx=t;
         }
      }
      printf("Case %d: %d\n",eset,mx);
   }


   return 0;
}

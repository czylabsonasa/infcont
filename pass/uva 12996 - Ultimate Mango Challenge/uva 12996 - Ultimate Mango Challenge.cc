// type // simple
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int m[16];
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int t,s;scanf("%d%d",&t,&s);
      bool done=true;
      int ts=0;
      for(int i=0;i<t;i++){
         scanf("%d",&m[i]);
         ts+=m[i];
      }
      done=done&&(s>=ts);
      for(int i=0;i<t;i++){
         int mi;scanf("%d",&mi);
         done=done&&(m[i]<=mi);
      }
      if(done){
         printf("Case %d: Yes\n",eset);
      }else{
         printf("Case %d: No\n",eset);
      }
   }

   return 0;
}

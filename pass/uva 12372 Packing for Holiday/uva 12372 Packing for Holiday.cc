// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int a,b,c;scanf("%d%d%d",&a,&b,&c);
      if(a>b){swap(a,b);}
      if(b>c){swap(b,c);}


      printf("Case %d: %s\n",eset,(c>20?"bad":"good"));
   }

   return 0;
}

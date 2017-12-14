// type // sort
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int n;scanf("%d",&n);
   for(int i=1;i<=n;i++){
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      if(a>b){swap(a,b);}
      if(b>c){swap(b,c);}
      if(a>b){swap(a,b);}
      printf("Case %d: %d\n",i,b);
   }
   return 0;
}

// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   while(esetek--){
      int x;scanf("%d",&x);
      x=(63*x+7492)*5-498;
      if(x<0){x=-x;}
      printf("%d\n",(x%100)/10);
   }

   return 0;
}

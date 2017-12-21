// type // quadratic eq.
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int d,r,t;
   while(3==scanf("%d%d%d",&d,&r,&t)){
      int s=r+t;
      int c=s;
      if(d>=2){
         c-=((d-1)*(d+6))/2;
      }
      int b=d+5; //(x-2)(x-2+b)=c
      int x=int(0.5*(sqrt(b*b+4*c)-b)+1e-12);
      x=x+2;
      printf("%d\n",((x+3)*(x-2))/2-t);

   }
   return 0;
}

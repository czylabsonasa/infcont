// type // simple
// todo: make a problem that requires to compute the probabilty too
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int a,b;
   while(2==scanf("%d%d",&a,&b)){
      if(b>a){swap(a,b);}
      printf("%d\n",a);
   }


   return 0;
}

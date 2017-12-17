// type // fibo
// fiu(m+1)=lany(m)
// lany(m+1)=fiu(m)+lany(m)=fiu(m)+fiu(m-1)+lany(m-1)
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   unsigned long long int seq[82]={1,1,2,3};
   for(int i=4;i<=80;i++){
      seq[i]=seq[i-1]+seq[i-2];
   }

   while(1){
      int n;scanf("%d",&n);
      if(0==n){
         break;
      }
      printf("%llu\n",seq[n]);

   }


   return 0;
}

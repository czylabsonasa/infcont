// type // prime // sieve
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

void primeSieve(int* p,int const N){
   for(int i=4;i<N;){
      p[i++]=0;
      p[i++]=1;
   }
   p[0]=p[1]=0;
   p[2]=p[3]=1;

   for(int i=3,i2=9;i2<N;i2+=((i+1)<<2),i+=2){
      if(1==p[i]){
         int j=i2;
         int const delta=(i<<1);
         while(j<N){
            p[j]=0;//last factor
            j+=delta;
         }
      }
   }
}

int const N=1000008;
int prime[N];

int main(){
   char dig[10];
   primeSieve(prime,N);
   prime[1]=1;
   while(1){
      int n;scanf("%d",&n);
      printf("%d\n",2*n);
      if(prime[n]){
         int ndig=0;
         while(n>0){
            dig[ndig++]=n%10;
            n/=10;
         }
         int i=0;ndig--;
         while(i<ndig&&dig[i]==dig[ndig]){
            i++;--ndig;
         }
         if(i>=ndig){
            break;
         }
      }
   }


   return 0;
}

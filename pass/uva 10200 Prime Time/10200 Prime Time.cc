// type // prime // number
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int const Np=2000;
int primes[Np+1]={2,3,5,7,11,13,17,19,23};
void fillPrimes(){
   int i=9, jelolt=23, k=2;
   while(i<=Np){
      jelolt+=k ;
      k=6-k;
      int j=2;
//      while( ULLI( pr[ j ] ) * pr[ j ] <= cp )
      while(primes[j]<=jelolt/primes[j]){
         if(0==jelolt%primes[j]){
            j=-1;
            break;
         }
         j++ ;
      }
      if(j>0){
         primes[i++]=jelolt;
//if(jelolt>10000){printf("    %d\n",i);}
      }
   }
}
int isprime(int n){
   if(1==n){
      return 0;
   }
   if(2==n||3==n){
      return 1;
   }
   if(0==n%2||0==n%3){
      return 0;
   }
   int i=2;
   while(1){
      int pi=primes[i++];
      int q=n/pi;
      if(pi>q){
         return 1;
      }
      if(pi*q==n){
         return 0;
      }
   }
}

int const E=10000;
int buff[E+3]={0};

int main(){

   fillPrimes();
   //~ for(int i=0;i<=Np;i++){
      //~ printf("%d\n",primes[i]);
   //~ }
   int* p=&buff[1];
   for(int n=0;n<=E;n++){
      int fn=n*n+n+41;
      p[n]=isprime(fn);
      p[n]+=p[n-1];
//printf("%d %d %d\n",n,fn,isprime(fn));
   }

   int a,b;
   while(2==scanf("%d%d",&a,&b)){
      double perc=100.0*(p[b]-p[a-1])/double(b-a+1);
      printf("%.2lf\n",perc+1e-12);
   }
 


   return 0;
}

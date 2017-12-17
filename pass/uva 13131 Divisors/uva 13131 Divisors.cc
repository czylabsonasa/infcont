// type // primes //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int const Np=800;//500000<800^2
int primes[Np+1]={2,3,5,7,11,13,17,19,23};
void fillPrimes(){
   int i=9, jelolt=23, k=2;
   while(i<=Np){
      jelolt+=k ;
      k=6-k;
      int j=2;
      while(primes[j]<=jelolt/primes[j]){
         if(0==jelolt%primes[j]){
            j=-1;
            break;
         }
         j++ ;
      }
      if(j>0){
         primes[i++]=jelolt;
      }
   }
}

//factorisation based
int sumDiv(int n){
   if(1==n){return 1;}
   if(4>n){return 1+n;}

   int ans=1;
   for(int i=0;n>1;i++){
      int const p=primes[i];
      if(p>n/p){
         break;
      }
      int pk=p;
      while(0==n%pk){
         pk*=p;
      }
      n/=(pk/p);
      if(pk>p){
         ans*=((pk-1)/(p-1));
      }
   }
   if(n>1){
      ans*=(n+1);
   }
   return ans;
}

int main(){
   fillPrimes();
   //~ for(int i=0;i<33;i++){
      //~ printf("%d\n",primes[i]);
   //~ }

   int esetek;scanf("%d",&esetek);
   while(esetek--){
      int n,k;
      scanf("%d%d",&n,&k);
      int ans=0;
      while(1){
         if(1==k){
            ans=0;
            break;
         }
         if(k>n||n%k){
            ans=sumDiv(n);
            break;
         }
         ans=sumDiv(n)-k*sumDiv(n/k);
         break;
      }
      printf("%d\n",ans);
   }

   return 0;
}

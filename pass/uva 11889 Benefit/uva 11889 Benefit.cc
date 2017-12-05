// type // numbers // divisibility // primes
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a0,int a1){
   int a2;
   while((a2=(a0%a1))){
      a0=a1;
      a1=a2;
   }
   return a1;
}

void sieveIt(int* p,int const N){
   for(int i=4;i<N;){
      p[i++]=2;
      p[i++]=1;
   }
   p[0]=p[1]=0;
   p[2]=p[3]=1;

   for(int i=3,i2=9;i2<N;i2+=((i+1)<<2),i+=2){
      if(1==p[i]){
         int j=i2;
         int const delta=(i<<1);
         while(j<N){
            p[j]=i;//last factor
            j+=delta;
         }
      }
   }
}

int const GYN=3333;
int prime[GYN];
int main(){
   sieveIt(prime,GYN);

   int esetek; scanf("%d",&esetek);
   while(esetek--){
      int a,c,lnko;
      scanf("%d%d",&a,&c);
      if(0!=c%a){
         printf("NO SOLUTION\n");
         continue;
      }
      lnko=gcd(a,c/a);//lnko*lnko<=c<=10^7
      while(lnko>1){
         int p=prime[lnko];
         if(p>1){
            do{
               lnko/=p;
               a/=p;
            }while(0==lnko%p);
            while(0==a%p){
               a/=p;
            }
         }else{
            a/=lnko;
            while(0==a%lnko){
               a/=lnko;
            }
            lnko=1;
         }
      }
      printf("%d\n",c/a);
   }

   return 0;
}


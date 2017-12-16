// type // administration
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int const M=1000000;
char volt[M+3]={0};
int const N=10000;
int num[N+3];
int main(){

   int n;
   while(1==scanf("%d",&n)){
      int mx=-1;
      for(int i=0;i<n;i++){
         scanf("%d",&num[i]);
         mx=max(mx,num[i]);
      }
      int t; scanf("%d",&t);
      int a=-1,b=t,diff=t+1;
      for(int i=0;i<n;i++){
         int x=num[i];//it can be 2*mx
         if(x>=t||t-x>mx){
            continue;
         }
         if(volt[t-x]){
            if(abs(t-2*x)<diff){
               diff=abs(t-2*x);
               a=x;
               b=t-x;
            }
         }
         volt[x]=1;
      }
      //cleanup
      for(int i=0;i<n;i++){
         volt[num[i]]=0;;
      }
      if(a>b){swap(a,b);}
      printf("Peter should buy books whose prices are %d and %d.\n\n",a,b);

   }

   return 0;
}

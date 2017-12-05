// type // binomial numbers // i/o related
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int LLI;
int const N=50;
vector<LLI> binCoeff[N+1];

int main(){
   for(int i=0;i<=N;i++){
      binCoeff[i].resize(i+1);
      binCoeff[i][0]=binCoeff[i][i]=1;
   }
   for(int n=2;n<=N;n++){
      for(int k=1;k<n;k++){
         binCoeff[n][k]=binCoeff[n-1][k-1]+binCoeff[n-1][k];
      }
   }

   char line[256],a[128],b[128];
   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      int k;
      scanf("%s",line);
      for(int i=0;line[i];i++){
         switch(line[i]){
            case('('):{
               line[i]=' ';
               break;
            }
            case(')'):{
               line[i]=' ';
               break;
            }
            case('+'):{
               line[i]=' ';
               break;
            }
            case('^'):{
               line[i]=' ';
               break;
            }
         }
      }
      sscanf(line,"%s%s%d",a,b,&k);
      auto prt=[a,b,k](int i){
         if(binCoeff[k][i]>1){
            printf("%lld*",binCoeff[k][i]);
         }
         if(k-i>0){
            printf("%s",a);
            if(k-i>1){
               printf("^%d",k-i);
            }
         }
         if(k-i>0&&i>0){
            printf("*");
         }
         if(i>0){
            printf("%s",b);
            if(i>1){
               printf("^%d",i);
            }
         }
      };

      printf("Case %d: ",eset);
      for(int i=0;i<=k;i++){
         prt(i);
         if(i<k){
            printf("+");
         }
      }
      printf("\n");
//      printf("(%s+%s)^%d\n",a,b,k);
   }

   return 0;
}

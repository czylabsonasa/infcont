// type // floating point // computation
// absolute OR relative error?
// todo // apply addition formulas
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int p,a,b,c,d;
typedef double FL;//float wa
#define FS "%.8lf\n"
FL fun(FL k){
   return (sin(a*k+b)+cos(c*k+d))*p;
}
int main(){
   int n;
   while(6==scanf("%d%d%d%d%d%d",&p,&a,&b,&c,&d,&n)){
      FL x=fun(1.0);
      FL pmax=x;
      FL dec=0.0; //no decline
      for(int k=2;k<=n;k++){
         x=fun(FL(k));
         FL tdec=pmax-x;
         dec=max(dec,tdec);
         pmax=max(pmax,x);
      }
      if(dec<1e-8){
         printf("0\n");
      }else{
         printf(FS,dec);
      }
   }


   return 0;
}

// type // sort + dp
// O(n^2)
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct info{
   int w,s;//weight,strength
   bool operator<(const info&masik)const{
      return (s<masik.s)||((s==masik.s)&&(w<masik.w));
   }
};
info turt[6000];
int len2opt[6000];
int main(){
   int w,s,n=0;
   while(2==scanf("%d%d",&w,&s)){
      ++n;
      turt[n].w=w;
      turt[n].s=s;
   }
   sort(turt+1,turt+n+1);
   int mx=0;
   len2opt[0]=0;
   for(int i=1;i<=n;i++){
      int s=turt[i].s;
      int w=turt[i].w;
      int it=mx-1;
      s-=w;
      if(s>=len2opt[mx]){
         len2opt[mx+1]=w+len2opt[mx];
         ++mx;
      }
      while(it>=0){
         if(s>=len2opt[it]){
            len2opt[it+1]=min(len2opt[it+1],len2opt[it]+w);
         }
         it--;
      }
   }
   printf("%d\n",mx);


   return 0;
}

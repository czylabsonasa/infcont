// type // triangle inequality // easy
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
   int esetek;scanf("%d",&esetek);
   while(esetek--){
      int a,b,c;scanf("%d%d%d",&a,&b,&c);
      if(a>b){swap(a,b);}
      if(b>c){swap(b,c);}
      if(a>b){swap(a,b);}
      if(a+b>c){
         printf("OK\n");
      }else{
         printf("Wrong!!\n");
      }
   }

   return 0;
}

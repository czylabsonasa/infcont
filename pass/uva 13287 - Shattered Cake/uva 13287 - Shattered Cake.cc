// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define GETCHAR getchar_unlocked
bool getnum(int&x){
   int i;
   while(!(((i=GETCHAR())>='0')&&(i<='9'))&&i!=EOF);
   if(i==EOF){
      return false;
   }
   x=(i-'0');
   while(((i=GETCHAR())>='0')&&(i<='9')){
      x=((x<<1)+(x<<3)+(i-'0'));
   }
   return true;
}

int main(){

   int w,n;
   while(getnum(w)){
      getnum(n);
      int lw=0;
      for(int i=0;i<n;i++){
         int a,b;
         getnum(a);getnum(b);
         lw+=a*b;
      }
      printf("%d\n",lw/w);
   }

   return 0;
}

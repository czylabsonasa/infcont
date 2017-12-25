// type // numbers // base 2 representation
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long int LLI;
#define GETCHAR getchar_unlocked
template<typename T> T getNum(void){
   register int i;
   while(!(((i=GETCHAR())>='0') && (i<='9')));
   register T ans = (i-'0');
   while(((i=GETCHAR())>='0')&&(i<='9')){
      ans=((ans<<1)+(ans<<3)+(i-'0'));
   }
   return ans;
}
template<typename T,int N> struct num2Str{
   char buff[N];
   num2Str(){
      buff[N-1]=0;
   }
   char* operator()(T x){
      register char*p=&buff[N-1];
      do{
         *(--p)='0'+(x%10);
         x/=10;
      }while(x>0);
      return p;
   }
};
char* cat(char* beg, const char* end){
   while((*beg=*end)){
      ++beg;++end;
   }
   return beg;
}

int const OLIM=2000;
char out[2*128*1024];
int main(){
   char*pout=out;
   int nout=0;
   num2Str<int,16> sint;
   num2Str<LLI,32> sLLI1,sLLI2;


   int esetek = getNum<int>();
   for(int eset=1; eset<=esetek; eset++){
      register LLI A = getNum<LLI>(), B = getNum<LLI>();
      register LLI resOR=0ULL, resAND=0ULL,
      diff = B-A, egy = 1ULL,
      part = 0;
      while(egy && B>=egy){
         bool ch = (egy<=diff+part);//there is a change in (A,B]
         if(egy & A){
            resOR = resOR|egy;
            if(!ch){
               resAND = resAND|egy;
            }
            part = part|egy;
         }else{
            if(ch){
               resOR = resOR|egy;
            }
         }
         egy = (egy << 1);

      }
      if(nout>=OLIM){
         fputs_unlocked(out,stdout);
         nout=0;
         pout=out;
      }
//      sprintf(pout,"Case %d: %llu %llu\n", eset, resOR, resAND );
      pout = cat(pout, "Case ");
      pout = cat(pout, sint(eset));
      pout = cat(pout, ": ");
      pout = cat(pout, sLLI1(resOR));
      pout = cat(pout, " ");
      pout = cat(pout, sLLI2(resAND));
      pout = cat(pout, "\n" );
      nout++;
   }

   if(nout>0){
      fputs_unlocked(out,stdout);
   }

   return 0;
}

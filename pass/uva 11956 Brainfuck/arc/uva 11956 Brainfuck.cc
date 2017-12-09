// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
struct BF{
   int const N;
   vector<unsigned char> tape;
   int pos;
   BF(int _N):N(_N),tape(N),pos(0){}
   void clear(){
      fill(tape.begin(),tape.end(),0);
      pos=0;
   }
   void exec(const char* prog){
      for(int i=0;prog[i];i++){
         switch(prog[i]){
            case('>'):{
               ++pos;
               if(pos>=N){pos=0;}
               break;
            }
            case('<'):{
               --pos;
               if(pos<0){pos=N-1;}
               break;
            }
            case('+'):{
               ++tape[pos];
               break;
            }
            case('-'):{
               --tape[pos];
               break;
            }
            case('.'):{
               break;
            }
         }
      }
   }
   unsigned char state(int i){
      return tape[i];
   }
};
char prog[128*1024];//32 volt
char d2h[256][3];
int main(){
   for(int i=0;i<256;i++){
      int q=i/16;
      int r=i%16;
      if(r>9){
         r='A'+r-10;
      }else{
         r=r+'0';
      }
      if(q>9){
         q='A'+q-10;
      }else{
         q=q+'0';
      }
      d2h[i][0]=q;
      d2h[i][1]=r;
      d2h[i][2]=0;
   }

   int const T=100;
   BF bf(T);
   //~ bf.exec("-");
   //~ printf("%u\n",bf.state(0));


   int esetek;scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      scanf("%s",prog);
      bf.clear();
      bf.exec(prog);
      printf("Case %d:",eset);
      for(int i=0;i<T;i++){
         printf(" %s",d2h[bf.state(i)]);
      }
      printf("\n");
   }


   return 0;
}

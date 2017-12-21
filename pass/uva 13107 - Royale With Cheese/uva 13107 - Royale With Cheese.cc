// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char in[100008];
char out[200008];
char volt[128];
char map[27][2]={
   {'0','0'},
   {'0','1'},
   {'0','5'},//{'0','2'},
   {'0','3'},
   {'0','4'},
   {'0','2'},//{'0','5'},
   {'0','9'},//{'0','6'},
   {'0','7'},
   {'0','8'},
   {'0','6'},//{'0','9'},
   {'1','0'},
   {'1','1'},
   {'1','5'},//{'1','2'},
   {'1','3'},
   {'1','4'},
   {'1','2'},//{'1','5'},
   {'1','9'},//{'1','6'},
   {'1','7'},
   {'1','8'},
   {'1','6'},//{'1','9'},
   {'5','0'},//{'2','0'},
   {'5','1'},//{'2','1'},
   {'5','5'},//{'2','2'},
   {'5','3'},//{'2','3'},
   {'5','4'},//{'2','4'},
   {'5','2'},//{'2','5'},
   {'5','9'} //{'2','0'},
};

int main(){
   while(1==scanf("%s",in)){
      for(int i='a';i<='z';i++){
         volt[i]=0;
      }
      int nvolt=0;
      int nout=0;
      int j;
      for(int i=0;(j=in[i]);i++){
         if(0==volt[j]){
            volt[j]=++nvolt;
         }
         if((j=volt[j])>9){
            out[nout++]=map[j][0];
            out[nout++]=map[j][1];
         }else{
            out[nout++]=map[j][1];
         }
      }
      out[nout]=0;
      printf("%s\n",out);
   }

   return 0;
}

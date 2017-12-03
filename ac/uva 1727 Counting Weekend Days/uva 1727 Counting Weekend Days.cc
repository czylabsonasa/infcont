// type // implementation // bruteforce
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;
int main(){
   typedef const char* ccc;
   tuple<ccc,int> data[12]={
      {"JAN",31},{"FEB",28},{"MAR",31},
      {"APR",30},{"MAY",31},{"JUN",30},
      {"JUL",31},{"AUG",31},{"SEP",30},
      {"OCT",31},{"NOV",30},{"DEC",31}
   };
   ccc napok[7]={
      "FRI","SAT","SUN","MON","TUE","WED","THU"
   };


   char mon[4],fd[4];
   int esetek;
   scanf("%d",&esetek);
   while(esetek--){
      scanf("%s%s",mon,fd);
      int it=0;
      while(strcmp(get<0>(data[it]),ccc(mon))){
         it++;
      }
      int nod=get<1>(data[it]);

      it=0;
      while(strcmp(napok[it],ccc(fd))){
         it++;
      }
      int ans=0;
      for(int i=1;i<=nod;i++){
         if(it<2){
            ++ans;
         }
         it=(it+1)%7;

      }
      printf("%d\n",ans);

   }


   return 0;
}

// type // search // backtracking // sort
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
struct data{
   char name[32];
   int a;
   int d;
   bool operator<(const data& masik)const{
      return strcmp(name,masik.name)<0;
   }
};

data adat[10];
int bestA,bestD;
char best[10],tmp[10];
void gen(int level,int nch,int A,int D){
   if(5==nch){
      if(A>bestA){
         bestA=A;
         bestD=D;
         for(int i=0;i<10;best[i]=tmp[i],i++);
         return;
      }
      if(A==bestA){
         if(D>bestD){
            bestD=D;
            for(int i=0;i<10;best[i]=tmp[i],i++);
         }
      }
      return;
   }
   tmp[level]=1;
   gen(level+1,nch+1,A+adat[level].a,D-adat[level].d);
   tmp[level]=0;
   if(nch+9-level>=5){
      gen(level+1,nch,A,D);
   }
}

int main(){
   int sD;

   int esetek;
   scanf("%d",&esetek);
   for(int eset=1;eset<=esetek;eset++){
      sD=0;//wa
      for(int i=0;i<10;i++){
         scanf("%s%d%d",adat[i].name,&adat[i].a,&adat[i].d);
         sD+=adat[i].d;
      }
      sort(adat,adat+10);
      bestA=bestD=0;//wa
      gen(0,0,0,sD);

      printf("Case %d:\n",eset);

      auto out=[](int const v){//adat,best is global
      bool elso=true;
         for(int i=0;i<10;i++){
            if(v==best[i]){
               if(elso){
                  elso=false;
                  printf("(%s",adat[i].name);
               }else{
                  printf(", %s",adat[i].name);
               }
            }
         }
         printf(")\n");
      };
      out(1);
      out(0);

   }

   return 0;
}

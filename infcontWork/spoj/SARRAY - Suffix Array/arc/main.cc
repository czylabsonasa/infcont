#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int const LN=17;
int const N=(1<<LN)+3;

struct info{
   int suf;
   int box;
};
info table[1+LN][N];
int pos[N+3], npos[N+3];
char text[N+3];

int main(){
   scanf("%s", text);
   int const n=strlen(text);
   info* t=table[0];
   for(int i=0; i<n; i++){
      t[i].suf=i;
   }
   sort(t, t+n, [](const info& x, const info& y)->bool{return text[x.suf]<text[y.suf];});

   int pbox=t[0].box=0;
   pos[t[0].suf]=0;
   for(int i=1; i<n; i++){
      if(text[t[i].suf]!=text[t[i-1].suf]){++pbox;}
      t[i].box=pbox;
      pos[t[i].suf]=i;
   }

   t[n]=info{n, -2};//sentinel
   int step=1;
   for(int d=1; d<n; ++step, d<<=1){
      t=table[step-1];
      info* tt=table[step];

      bool volt=false;
      int beg=0;
      int rbox=-1;
      pbox=t[0].box;
      tt[0]=t[0];
      for(int i=1; i<=n; ++i){
         tt[i]=t[i];
         if(t[i].box!=pbox){
            for(int j=beg; j<i; ++j){
               if(tt[j].suf+d<n){
                  tt[j].box=t[pos[t[j].suf+d]].box;
               }else{
                  tt[j].box=-1;
               }
            }
            if(i-beg>1){
               volt=true;
               sort(tt+beg, tt+i, [](const info& x, const info& y)->bool{return x.box<y.box;});
            }

            pbox=tt[beg].box;
            tt[beg].box=(++rbox);
            npos[tt[beg].suf]=beg;
            for(int j=beg+1; j<i; ++j){
               npos[tt[j].suf]=j;
               if(tt[j].box==pbox){
                  tt[j].box=rbox;
               }else{
                  pbox=tt[j].box;
                  tt[j].box=(++rbox);
               }
            }

            pbox=tt[i].box;
            beg=i;
         }
      }
      if(false==volt){
         break;
      }
      swap(pos, npos);
   }//step

   t=table[step-1];
   for(int i=0; i<n; i++){
      printf("%d\n", t[i].suf);
   }

   return 0;
}

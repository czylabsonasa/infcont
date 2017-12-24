// type //
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

#define GETCHAR getchar_unlocked
int GETNUM(void){
   int i,ans;
   while(!(((i=GETCHAR())>='0')&&(i<='9')));
   ans=(i-'0');
   while(((i=GETCHAR())>='0')&&(i<='9')){
      ans=((ans<<1)+(ans<<3)+(i-'0'));
   }
   return ans;
}



int const N=1008;
char table[N][N];
int dist[N][N];
char dir[8][2]={
   {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}
};
char nxt[8]={1,2,3,4,5,6,7,0};
int const INF=1000000000;

#define _traj(_insert)\
   x=sx+dir[it][0];\
   y=sy+dir[it][1];\
   if(table[x][y]){\
      if(d<dist[x][y]){\
         dist[x][y]=d;\
         _insert((x<<10)+y);\
      }\
   }\
   it=nxt[it];

int main(){


   int nr=GETNUM();
   int nc=GETNUM();
   for(int i=1;i<=nr;i++){
      for(int j=1;j<=nc;){
         int c=GETCHAR();
         if('0'<=c&&c<='9'){
            table[i][j]=c;
            ++j;
         }
      }
      table[i][0]=0;
   }
   memset(table[0],0,nc+2);
   memset(table[nr+1],0,nc+2);


   deque<int> ks;

   int nq=GETNUM();
   for(int iq=0;iq<nq;iq++){
      int sx=GETNUM();
      int sy=GETNUM();
      int tx=GETNUM();
      int ty=GETNUM();

      //"plain" distance
      int ans=min(abs(sx-tx),abs(sy-ty))+abs(abs(sx-tx)-abs(sy-ty));
      if(ans>0){
         for(int i=1;i<=nr;i++){
            for(int j=1;j<=nc;j++){
               dist[i][j]=INF;
            }
         }

         ks.clear();
         dist[sx][sy]=0;
         ks.push_front((sx<<10)+sy);
         while(!ks.empty()){
            int s=ks.front();ks.pop_front();
            sx=s>>10;
            sy=s&1023;
            int d=dist[sx][sy];
            if((d>ans)||(sx==tx&&sy==ty)){
               break;
            }
            int it=table[sx][sy]-'0';
            int x,y;
            _traj(ks.push_front); ++d;
            _traj(ks.push_back);
            _traj(ks.push_back);
            _traj(ks.push_back);
            _traj(ks.push_back);
            _traj(ks.push_back);
            _traj(ks.push_back);
            _traj(ks.push_back);
         }
         ans=dist[tx][ty];
      }
      printf("%d\n",ans);
   }



   return 0;
}

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



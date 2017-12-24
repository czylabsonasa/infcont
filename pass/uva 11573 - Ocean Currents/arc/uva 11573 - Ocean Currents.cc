// type //
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;
int const N=1008;
char table[N][N];
int dist[N][N];
char dir[8][2]={
   {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}
};
char nxt[8]={1,2,3,4,5,6,7,0};
int const INF=1000000000;

int main(){


   int nr,nc;scanf("%d%d",&nr,&nc);
   for(int i=1;i<=nr;i++){
      scanf("%s",&table[i][1]);
      table[i][0]=0;
   }
   memset(table[0],0,nc+2);
   memset(table[nr+1],0,nc+2);


   deque<int> ks;

   int nq;scanf("%d",&nq);
   for(int iq=0;iq<nq;iq++){
      int sx,sy,tx,ty;
      scanf("%d%d%d%d",&sx,&sy,&tx,&ty);

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
            for(int i=0;i<8;i++){
               int x=sx+dir[it][0];
               int y=sy+dir[it][1];
               if(x>0&&x<=nr&&y>0&&y<=nc){
                  if(d<dist[x][y]){
                     dist[x][y]=d;
                     if(0==i){
                        ks.push_front((x<<10)+y);
                     }else{
                        ks.push_back((x<<10)+y);
                     }
                  }
               }
               if(0==i){++d;}
               it=nxt[it];
            }
         }
         ans=min(ans,dist[tx][ty]);
      }
      printf("%d\n",ans);
   }



   return 0;
}

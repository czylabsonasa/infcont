// tag // implementation // floodfill
// wa: cylinder like the map
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int const T=32;
char tabla[T][T];//wired in limits
int area,r,c;
void gen(int x,int y){
   tabla[x][y]=-1;
   area+=1;
   if(x+1<r&&tabla[x+1][y]>0){
      gen(x+1,y);
   }
   if(x-1>=0&&tabla[x-1][y]>0){
      gen(x-1,y);
   }
   if(tabla[x][(y+1)%c]>0){
      gen(x,(y+1)%c);
   }
   if(tabla[x][(y-1+c)%c]>0){
      gen(x,(y-1+c)%c);
   }
}
int main(){
   while(2==scanf("%d%d",&r,&c)){
      //read
      for(int i=0;i<r;i++){
         scanf("%s",tabla[i]);
      }
      int x,y;scanf("%d%d",&x,&y);
      //transform water into -1
      int land=tabla[x][y];
      for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
            if(tabla[i][j]!=land){
               tabla[i][j]=-1;
            }
         }
      }

      //fill the home continent with -1's
      area=0;
      gen(x,y);
//      printf("::: %d\n",area);

      //explore all of the other ones
      int ans=0;
      for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
            if(tabla[i][j]==land){
               area=0;
               gen(i,j);
               ans=max(ans,area);
            }
         }
      }
      printf("%d\n",ans);

   }//main loop


   return 0;
}

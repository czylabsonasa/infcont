// type // simulation // table
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
namespace dir{
   int dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
   enum dirName{E=0,N=1,W=2,S=3};
   int left[4]={1,2,3,0};
   int right[4]={3,0,1,2};
   int loc[2]={-1,-1};
   int tloc[2]={-1,-1};
   int adir;
   void init(int ad,int x,int y){
      adir=ad;
      loc[0]=x;loc[1]=y;
   }
   void turnL(){
      adir=left[adir];
   }
   void turnR(){
      adir=right[adir];
   }
   int* get(){
      return dir[adir];
   }
   int* move(){
      tloc[0]=loc[0]+dir[adir][0];
      tloc[1]=loc[1]+dir[adir][1];
      return tloc;
   }
   void accept(){
      loc[0]=tloc[0];
      loc[1]=tloc[1];
   }
};

int const sT=128;
char table[sT][sT];
int const sC=64*1024;
char cmd[sC];

int main(){
   while(1){
      int r,c,np;
      scanf("%d%d%d",&r,&c,&np);
      if(0==r+c+np){
         break;
      }
      for(int i=0;i<r;i++){
         scanf("%s",table[i]);
      }
      scanf("%s",cmd);

      //searching for starting pos&dir
      bool found=false;
      for(int i=0;i<r&&!found;i++){
         char*ti=table[i];
         for(int k=0;ti[k]&&!found;k++){
            switch(ti[k]){
               case('N'):{
                  dir::init(1,i,k);
                  ti[k]='.';
                  found=true;
                  break;
               }
               case('S'):{
                  dir::init(3,i,k);
                  ti[k]='.';
                  found=true;
                  break;
               }
               case('L'):{
                  dir::init(0,i,k);
                  ti[k]='.';
                  found=true;
                  break;
               }
               case('O'):{
                  dir::init(2,i,k);
                  ti[k]='.';
                  found=true;
                  break;
               }
            }//switch
         }
      }

      //execute commands
      int ans=0;
      for(int i=0;cmd[i];i++){
         switch(cmd[i]){
            case('F'):{
               int* tloc=dir::move();
               int tx=tloc[0];int ty=tloc[1];
               if(0<=tx&&tx<r&&0<=ty&&ty<c){
                  if(table[tx][ty]!='#'){
                     dir::accept();
                     if(table[tx][ty]=='*'){
                        ans++;
                        table[tx][ty]='.';
                     }
                  }
               }
               break;
            }//move
            case('D'):{//right
               dir::turnR();
               break;
            }
            case('E'):{//left
               dir::turnL();
               break;
            }
         }
      }//commands

      printf("%d\n",ans);
   }//esetek


   return 0;
}

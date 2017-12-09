// type // administration
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
char pic[128*1024];
int main(){
   int esetek;scanf("%d",&esetek);
   while(esetek--){
      int m,y,c;
      scanf("%d%d%d%s",&m,&y,&c,pic);
      int check=10;
      for(int i=0;pic[i];i++){
         switch(pic[i]){
            case('M'):{--m;break;}
            case('Y'):{--y;break;}
            case('C'):{--c;break;}
            case('R'):{--m;--y;break;}
            case('G'):{--y;--c;break;}
            case('V'):{--c;--m;break;}
            case('B'):{--m;--y;--c;break;}
         }
         if(--check==0){
            check=10;
            if(m<0||y<0||c<0){
               break;
            }
         }
      }
      if(m<0||y<0||c<0){
         printf("NO\n");
      }else{
         printf("YES %d %d %d\n",m,y,c);
      }
   }

   return 0;
}

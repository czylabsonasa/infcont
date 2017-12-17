// type // search // disjoint set
// two-pole world
// nehez megfogalmazni, de erdekes feladat
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct disjointSet{
   int H;
   vector<int> holvan;
   disjointSet(int tH=1000):H(tH),holvan(H){}
   void clear(int aH){
      if(aH>H){
         H=aH;
         holvan.resize(H);
      }
      for(int i=0;i<aH;i++){
         holvan[i]=-1;
      }
   }
   int find(int t){ // utfelezeses (PathHalving)
      int ht,hht;
      if((ht=holvan[t])>=0){
         while((hht=holvan[ht])>=0){
            holvan[t]=hht;
            t=ht;
            ht=hht;
         }
         t=ht;
      }
      return t;
   }
   int find_(int t){ // tomoriteses (PathCompressing)
      int ht,ans;
      ans=ht=t;
      while((ht=holvan[ht])>=0){
         ans=ht ;
      }
      while((ht=holvan[t])>=0){
         holvan[t]=ans;
         t=ht;
      }
      return ans;
   }
   void unio(int a,int b){
      holvan[a]=b;
   }
};


int main(){

   int n;scanf("%d",&n);
   disjointSet ds(n);
   ds.clear(n);
   vector<int> en(n,-1);
   while(1){
      int cmd,A,B;scanf("%d%d%d",&cmd,&A,&B);
      if(0==cmd){
         break;
      }
      int fA=ds.find(A);
      int fB=ds.find(B);
      int eA=en[fA];if(eA>=0){eA=ds.find(eA);}
      int eB=en[fB];if(eB>=0){eB=ds.find(eB);}
//printf("   %d %d %d\n",cmd,A,B);

      switch(cmd){
         case(1):{//setFriend
            if(fA==fB){
               break;
            }
            if(eA==fB||eB==fA){//?
               printf("-1\n");
               break;
            }
            if(eA>=0&&eB>=0){
               if(eB!=eA){
                  ds.holvan[eB]=eA;
               }
            }else{
               if(eB>=0){
                  en[fA]=eB;
                  en[eB]=fA;
               }
            }

            ds.holvan[fB]=fA;
            break;
         }
         case(2):{//setEnemy
            if(fA==fB){
               printf("-1\n");
            }else{
               en[fA]=fB;
               en[fB]=fA;
               if(eB>=0&&eB!=fA){
                  ds.holvan[eB]=fA;
               }
               if(eA>=0&&eA!=fB){
                  ds.holvan[eA]=fB;
               }

            }
            break;
         }
         case(3):{//areFriend
            if(fA==fB){
               printf("1\n");
            }else{
               printf("0\n");
            }
            break;
         }
         case(4):{//areEnemy
            if(eA>=0&&eA==fB){
               printf("1\n");
            }else{
               printf("0\n");
            }
            break;
         }
      }//switch
   }//read

   return 0;
}

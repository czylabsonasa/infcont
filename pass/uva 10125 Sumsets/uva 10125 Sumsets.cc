// type // sort // search,merge
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int const INF=2000000000;
int const N=1008;
int nums[N];
struct info{
   int val;
   short int i,j;
   bool operator<(const info& masik)const{
      return val>masik.val;
   }
   bool disjoint(const info& masik)const{
      if(i==masik.i||i==masik.j||j==masik.i||j==masik.j){
         return false;
      }
      return true;
   }
};
info sum[N*N/2],diff[N*N];
int main(){
   while(1){
      int n;scanf("%d",&n);
      if(0==n){
         break;
      }
      for(int i=0;i<n;i++){
         scanf("%d",&nums[i]);
      }


      int ns=0,nd=0;
      for(int i=1;i<n;i++){
         int ni=nums[i];
         for(int j=0;j<i;j++){
            sum[ns].i=i;sum[ns].j=j;sum[ns].val=ni+nums[j];ns++;
            diff[nd].i=i;diff[nd].j=j;diff[nd].val=ni-nums[j];nd++;
            diff[nd].i=j;diff[nd].j=i;diff[nd].val=nums[j]-ni;nd++;
         }
      }

      sort(sum,sum+ns);
      sort(diff,diff+nd);
//~ for(int i=0;i<ns;i++){
   //~ printf("%d (%d,%d)\n",sum[i].val,sum[i].i,sum[i].j);
//~ }
//~ printf("--------\n");
//~ for(int i=0;i<ns;i++){
   //~ printf("%d (%d,%d)\n",diff[i].val,diff[i].i,diff[i].j);
//~ }
      int d=-INF;
      bool found=false;
      if(n>=4){
         int is=0;
         int id=0;
         while(1){
            diff[nd].val=-INF;
            while(diff[id]<sum[is]){
               id++;
            }

            sum[ns].val=-INF;
            while(sum[is]<diff[id]){
               is++;
            }
   //printf("   %d %d\n",is,id);

            if(is==ns||id==nd){
               break;
            }

            int val=sum[is].val;
            if(val==diff[id].val){

               int ts=is+1;
               while(sum[ts].val==val){
                  ts++;
               }
               int td=id+1;
               while(diff[td].val==val){
                  td++;
               }
               for(int i=is;i<ts;i++){
                  for(int j=id;j<td;j++){
                     if(sum[i].disjoint(diff[j])){
      //~ printf("-------\n%d (%d,%d)\n",sum[i].val,sum[i].i,sum[i].j);
      //~ printf("%d (%d,%d)\n--------\n",diff[j].val,diff[j].i,diff[j].j);
                        if(nums[diff[j].i]>d){
                           d=nums[diff[j].i];
                           found=true;
                        }
                     }
                  }
               }
               is=ts;id=td;
            }//sum==diff
         }//while(1)
      }//n>=4
      if(found){
         printf("%d\n",d);
      }else{
         printf("no solution\n");
      }


   }

   return 0;
}

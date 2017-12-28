// type // sort, search // intervals, points
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <tuple>
#include <set>
using namespace std;
typedef tuple<int, int, int> info;
info lista[22222];
#define TIP get<1>
#define VAL get<0>
#define IDX get<2>
char manu[10008][22];
int res[1008];
set<int> op;

int main(){
   int esetek; scanf("%d", &esetek);
   while(1){// fail if no case
      int nd; scanf("%d", &nd);
      int nl=0;
      for(int i=0; i<nd; i++){
         int lo, hi;
         scanf("%s%d%d", manu[i], &lo, &hi);
         lista[nl++] = info{lo,-1, i};
         lista[nl++] = info{hi, 1, i};
      }
      int nq; scanf("%d", &nq);
      for(int i=0; i<nq; i++){
         int p; scanf("%d", &p);
         lista[nl++] = info{p, 0, i};
      }
      sort(lista, lista+nl);
      int nop=0;
      op.clear();
      for(int i=0; i<nl; i++){
         int tip, val, idx;
         tie(val, tip, idx) = lista[i];
         if(0 == tip){
            if(1 == nop){
               res[idx]=*op.begin();
            }else{
               res[idx]=-1;
            }
            continue;
         }
         if(-1 == tip){
            ++nop;
            op.insert(idx);
            continue;
         }
         if(1 == tip){
            --nop;
            op.erase(idx);
            continue;
         }
      }

      for(int i=0; i<nq; i++){
         if(res[i]<0){
            printf("UNDETERMINED\n");
         }else{
            printf("%s\n", manu[res[i]]);
         }
      }
      if(--esetek){
         printf("\n");
      }else{
         break;
      }
   }// esetek

   return 0;
}

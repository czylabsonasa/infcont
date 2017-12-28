// type // search // partial sum // fenwick
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

template<typename T, int N> struct Bit{
   int aN ;
   T tree[N+1] ;
   void init(int _aN){//aN<=N
      aN = _aN ;
      fill(tree,tree+aN+1,0);
   }
   T query(int x){
      T ans=0;
      while(x > 0){
         ans += tree[x];
         x -= (x&(-x));
      }
      return ans ;
   }
   void update(int x, const T val=1){
      while(x <= aN){
         tree[x] += val;
         x += (x&(-x));
      }
   }
} ;

int main(){
   int nums[5055];
   Bit<int, 5055> ft;

   int esetek; scanf("%d", &esetek);
   while(esetek--){
      int mx=-1;
      int n; scanf("%d", &n);
      for(int i=0; i<n; i++){
         scanf("%d", &nums[i]);
         mx=max(nums[i], mx);
      }

      ft.init(mx);
      ft.update(nums[0]);
      int ans=0;
      for(int i=1; i<n; i++){
         ans += ft.query(nums[i]);
         ft.update(nums[i]);
      }

      printf("%d\n", ans);
   }

   return 0;
}

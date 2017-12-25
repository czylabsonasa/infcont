// type // sorting
// todo: focus only on negatives in sort...
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define GETCHAR getchar_unlocked
int getNum(void){
   int i,ans;
   while(!(((i=GETCHAR())>='0')&&(i<='9')));
   ans=(i-'0');
   while(((i=GETCHAR())>='0')&&(i<='9')){
      ans=((ans<<1)+(ans<<3)+(i-'0'));
   }
   return ans;
}

int bal[1000008];//balance
typedef long long int LLI;
int main(){
   int esetek = getNum();
   for(int eset=1; eset<=esetek; eset++){
      int n = getNum();
      int k = getNum();
      for(int i=0; i<n; i++){
         bal[i] = getNum();
      }
      LLI sum=0;
      for(int i=0; i<n; i++){
         int t = getNum();
         bal[i] = t-bal[i];
         sum+=bal[i];
      }
      sort(bal, bal+n);
      int idx = 0;
      while(idx<k && bal[idx]<0){
         sum-=bal[idx];// mistake
         ++idx;
      }
      if(sum>0){
         printf("Case %d: %lld\n", eset, sum);
      }else{
         printf("Case %d: No Profit\n", eset);
      }
   }

   return 0;
}

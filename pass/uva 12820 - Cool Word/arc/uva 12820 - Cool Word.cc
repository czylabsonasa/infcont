// type //
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
template<typename T> int fmaker(T* beg, T* end, int *f){
   int mx=0;
   while(beg<end){
      if(*beg){
         int t=++f[*beg];
         if(t>mx){mx=t;}
      }
      ++beg;
   }
   return mx;
}
int main(){
   int wf[256]={0};
   int ff[64]={0};
   char w[64];

   int eset=0;
   int n;
   while(1==scanf("%d",&n)){
      int ans=0;
      for(int ni=0;ni<n;ni++){
         scanf("%s",w);
         fill(wf+'a',wf+'z'+1,0);
         fmaker<char>(w,w+strlen(w),wf);
         int mx=fmaker<int>(wf+'a',wf+'z'+1,ff);
         fill(ff,ff+mx+1,0);
         ans+=(1==mx);
      }
      printf("Case %d: %d\n",++eset,ans);
   }

   return 0;
}

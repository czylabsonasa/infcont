// type // array manipulation // frequencies
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
template<typename T> int fmaker(T* beg, T* end, int *f){
   int mx=0;
   while(beg<end){
      mx=max(int(*beg),mx);
      if(*beg){
         ++f[int(*beg)];
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
         int wlen=strlen(w);
         fmaker<char>(w,w+wlen,wf);
         if(1==wlen){continue;}//cool word has >=2 letters
         int mx=fmaker<int>(wf+'a',wf+'z'+1,ff);
//printf("------\n%s %d\n",w,mx);
         int idx=1;
         while(idx<=mx&&ff[idx]<2){
            ff[idx++]=0;
         }
         ans+=(idx>mx);
         while(idx<=mx){
            ff[idx++]=0;
         }
      }
      printf("Case %d: %d\n",++eset,ans);
   }

   return 0;
}

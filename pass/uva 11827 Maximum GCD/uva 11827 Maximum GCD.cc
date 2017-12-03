// type // numbers // gcd // io
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
bool getnum(char*& p,int& num){
   while(*p&&!(*p>='0'&&*p<='9')){
      ++p;
   }
   if(0==*p){
      return false;
   }
   num=*(p++)-'0';
   while((*p>='0'&&*p<='9')){
      num=10*num+(*(p++)-'0');
   }
   return true;
}
int gcd(int a0,int a1){
   int a2;
   while((a2=(a0%a1))){
      a0=a1;
      a1=a2;
   }
   return a1;
}

int main(){
   char line[4096];
   char*p;
   int nums[128],n;

   fgets(p=line,4000,stdin);
   int esetek;getnum(p,esetek);
   while(esetek--){
      fgets(p=line,4000,stdin);
      n=0;
      while(getnum(p,nums[n])){
         n++;
      }
      int ans=0;
      for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
            ans=max(ans,gcd(nums[i],nums[j]));
         }
      }
      printf("%d\n",ans);


   }

   return 0;
}

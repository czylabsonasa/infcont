// type // sort
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
   vector<int> st;
   while(1){
      int nst;scanf("%d",&nst);
      if(0==nst){
         break;
      }
      st.resize(nst);
      for(int i=0;i<nst;i++){
         scanf("%d",&st[i]);
      }
      sort(st.begin(),st.end());

      //odaut
      int mx=-1;
      for(int i=1;i<nst&&mx<201;i++){
         mx=max(mx,st[i]-st[i-1]);
      }
      //es a vissza
      mx=max(mx,2*(1422-st[nst-1]));

      if(mx<201){
         printf("POSSIBLE\n");
      }else{
         printf("IMPOSSIBLE\n");
      }
   }


   return 0;
}

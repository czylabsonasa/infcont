// type //
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int numdiv(int n){//n>1
   if(n<2){return 1;}
	int ans=2;
	int d=2;
	while(d<n/d){
		if(n%d==0){ans+=2;}
      d=d+1;
	}
	if(d*d==n){
		ans++;
   }
	return ans;
}
int main(){
   int p=1;
   for(int i=1;i<=100000&&p<1000000;i++){
      p=p+numdiv(p);
      printf("%d %d\n",i,numdiv(i));
   }
   


   return 0;
}

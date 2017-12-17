// type // sort // inversion count // merge
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define GETCHAR getchar_unlocked
int getnum(void){
   int i,ans;
   while(!(((i=GETCHAR())>='0')&&(i<='9')));
   ans=(i-'0');
   while(((i=GETCHAR())>='0')&&(i<='9')){
      ans=((ans<<1)+(ans<<3)+(i-'0'));
   }
   return ans;
}

// merge hibrid es inv szamolos opcioval ( makro )
#define _INVSZ( x ) x
#define _HIBRID( x ) x
#ifdef _HIBRID
#define _H 64
#endif
template<typename T> struct Merge{
   int xmeret;
   T* masolat;
   _INVSZ( unsigned long long int invsz ) ;
   Merge(int _xmeret){
      xmeret=_xmeret ;
      masolat=new T[xmeret];
      masolat+=1;// egyel balra mehet ...
   }
   ~Merge(){
      masolat-=1;
      delete []masolat;
   }

   void sort(T* eredeti,int n_eredeti){
      _INVSZ(invsz=0);
      sort(eredeti,eredeti+n_eredeti-1);
   }

   void sort(T* bal,T* jobb){
      _HIBRID(
      if((jobb-bal)<_H){
         T* tbal=bal+1;
         _INVSZ(unsigned int tinvsz=0);
         while(tbal<=jobb){
            T* t=tbal;
            T tert=(*t);
            while((t>bal)&&(tert<(*(t-1)))){
               (*t)=(*(t-1));
               t-=1;
            }
            _INVSZ(tinvsz+=(tbal-t));
            (*t)=tert;
            tbal+=1;
         }
         _INVSZ(invsz+=tinvsz);
         return;
      });

      T* kozep;
      if((kozep=(bal+((jobb-bal)>>1)))<jobb){
         sort(bal,kozep);
         sort(kozep+1,jobb);
         // osszefesul
         T* m=masolat;
         T* ujbal=kozep+1;
         while((bal<=kozep)&&(ujbal<=jobb)){
            if((*bal)>(*ujbal)){
               _INVSZ(invsz+=(1+kozep-bal));
               (*(m++))=(*(ujbal++));
            }else{
               (*(m++))=(*(bal++));
            }
         }

         while(bal<=kozep){
            (*(m++))=(*(bal++));
         }

         while(ujbal<=jobb){
            (*(m++))=(*(ujbal++));
         }

         while((--m)>=masolat){
            (*(jobb--))=(*m);
         }
      }
   }
};

int orig[100008];


int main(){
   Merge<int> merge(100008);
   while(1){
      int n=getnum();
      if(0==n){
         break;
      }
      for(int i=0;i<n;i++){
         orig[i]=getnum();
      }
      merge.sort(orig,n);
      printf("%s\n",(merge.invsz%2?"Marcelo":"Carlos"));
   }

   return 0;
}

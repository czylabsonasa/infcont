// type // sorting // string
// hogy lehet 1xubben?
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
char buff[1024*32];
char* lista[1024];
int main(){
   {
      char*p=buff;
      for(int i=0;i<1023;i++){
         lista[i]=p;
         p+=32;
      }
   }
   auto compare=[](char* a, char* b)->bool{
      return strcmp(a,b)<0;
   };
   while(1){
      int n; scanf("%d", &n);
      if(0==n){
         break;
      }
      for(int i=0; i<n; i++){
         scanf("%s", lista[i]);
      }
      sort(lista, lista+n, compare);
      int const m=n/2-1;
      char* a=lista[m];
      char* b=lista[m+1];

      while(*a == *b){//they are different
         ++a; ++b;
      }
      while(1){
         if(0 == *a){
            break;
         }
         if(0 == *(a+1)){
            break;
         }
         if(*b-*a > 1){
            ++(*a);
            *(a+1)=0;
            break;
         }
         if(*(b+1) != 0){
            ++(*a);
            *(a+1)=0;
            break;
         }
         ++a;
         while(*a>='Z'){
            ++a;
         }
         if(0 != *a && 0 != *(a+1)){
            ++(*a);
            *(++a)=0;
         }
         break;
      }

      printf("%s\n", lista[m]);
//      printf("%s %s\n", a, b);

   }

   return 0;
}

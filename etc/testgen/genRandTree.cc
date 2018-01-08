#include <cstdio>
#include <cstdlib>
#include <ctime>

int R(int a, int b){
   return a + ( rand() % ( b - a + 1 ) ) ;
}

int main(int np, char**p){
   int const lo=45000;
   int const up=50000;

   FILE* f=fopen("/dev/urandom","r");
   unsigned int s;
   fread(&s,1,4,f);
   fclose(f);

   srand(s);
   int n=R(lo, up);
   FILE* fin=fopen("IN","w");
   fprintf( fin , "%d\n" , n ) ;
   for(int i = 2; i <= n; ++i){
      int old=R(1,i-1);
      fprintf(fin, "%d %d\n", old, i);
   }

   int nq=R(10000,20000);
   fprintf( fin , "%d\n" , nq ) ;
   for(int i = 0; i < nq; ++i){
      int a=R(1,n);
      int b=R(1,n);
      fprintf(fin, "%d %d\n", a, b);
   }
   fprintf(fin, "0\n");


   fprintf(fin, "\n");
   fclose(fin) ;
   return 0 ;
}

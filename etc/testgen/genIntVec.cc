#include <cstdio>
#include <cstdlib>
#include <ctime>

int R(int a, int b){
   return a + ( rand() % ( b - a + 1 ) ) ;
}

int main(){
   FILE* f=fopen("/dev/urandom","r");
   unsigned int s;
   fread(&s,1,4,f);
   fclose(f);


   srand(s);
   int n=R(5, 25);
   FILE* fin=fopen("IN","w");
   fprintf( fin , "%d\n" , n ) ;
   for(int i = 0; i < n; ++i){
      int nxt=R(1,n/2+1);
      fprintf(fin, "%d ", nxt);
   }

   fprintf(fin, "\n");
   fclose(fin) ;
   return 0 ;
}

#include <cstdio>
#include <cctype>
using namespace std;

int main(int npar, char**par){
	if(npar<2){
		printf("sót kérek.\n");
		return 1;
	}
	FILE* f=fopen(par[1],"r");
	char tmp[64];
	char so[4096];
	char*p=so;
	while(1==fscanf(f, "%s", tmp)){
		char* q=tmp;
		while(*p=*q){
			p++; q++;
		}
	}
	*p=0;
	fclose(f);

	int i;
	while((i=getchar())!=EOF){
		if(0==*p){
			p=so;
		}
		putchar(i^(*p));
		++p;
	}
	return 0;
}

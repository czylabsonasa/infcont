#include <cstdio>
int main(int npar, char**par){
	if(npar<2){
		printf("sót kérek. (len<1024)\n");
	}
	char so[1024];
	char*p=so;
	for(int i=1;i<npar;i++){
		char*q=par[i];
		while(*p=*q){
			++p;++q;
		}
	}
	*p=0;
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

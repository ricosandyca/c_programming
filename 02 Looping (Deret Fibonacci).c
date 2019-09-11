#include <stdio.h>

int main (){
	
	int n,a,b,c,d,i;
	
	printf("Masukkan Data = ");
	scanf("%d", &n);
	
	a=1; b=1; i=1;
	
	while (i<=n){
		d=a;
		if (d<n){
			printf("%d  ", a);
			d++;
		}
		c=a+b;
		a=b;
		b=c;
		i++;
	}
	
}
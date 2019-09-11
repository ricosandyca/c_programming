#include <stdio.h>

int main (){
	
	int n;
	
	printf("Masukkan Data = ");
	scanf("%d", &n);
	
	if ( 0 <= n and n <= 20 ){
		printf("E");
	}
	else if ( 20 < n and n <= 40 ){
		printf("D");
	}
	else if ( 40 < n and n <= 60 ){
		printf("C");
	}
	else if ( 60 < n and n <= 80 ){
		printf("B");
	}
	else if ( 80 < n and n <= 100 ){
		printf("A");
	}
	else {
		printf("Coba Lagi");
	}
	
	return 0;
}
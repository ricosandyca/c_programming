#include <stdio.h>
#include <stdlib.h>

int menu,n,a,jumlah[50],harga[50];
FILE*rico;
char makanan[50][50];

int main(){
	
	rico=fopen("Praktikum.txt","w+");
	
	menu:;
	printf("Menu :\n");
	printf("1. Input\n2. View\n3. Exit\n");
	printf("Pilih Menu = ");
	scanf("%d",&menu);
	
	if (menu==1){
		input();
		system("cls");
		goto menu;
	}
	else if (menu==2){
		view();
		getch();
		system("cls");
		goto menu;
	}
	else if (menu==3){
		goto exit;
	}
	else{
		system("cls");
		goto menu;
	}
	exit:;
}

void input(){
	a=1;
	printf("Berapa Data = ");
	scanf("%d",&n);
	while(!(a>n)){
		printf("Data %d\n",a);
		printf("Makanan = ");
		scanf("%s",&makanan[a]);
		printf("Harga = ");
		scanf("%d",&harga[a]);
		printf("Jumlah = ");
		scanf("%d",&jumlah[a]);
		a++;
	}
}

void view(){
	a=1;
	while(!(a>n)){
		printf("\nData %d\n",a);
		printf("Makanan = %s\n",makanan[a]);
		printf("Harga = %d\n",harga[a]);
		printf("Jumlah = %d\n",jumlah[a]);
		fprintf(rico,"Data %d\n",a);
		fprintf(rico,"Makanan = %s\n",makanan[a]);
		fprintf(rico,"Harga = %d\n",harga[a]);
		fprintf(rico,"Jumlah = %d\n",jumlah[a]);
		fprintf(rico,"\n");
		a++;
	}
}
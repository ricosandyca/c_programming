#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main (){
	int menu,npm[50],n,a,delete,hapus,search,nosearch;
	char nama[50][50];
	
	menu:;
	printf("==========\n");
	printf("Menu :\n");
	printf("1. Input\n2. View\n3. Search\n4. Delete\n5. Exit\n");
	printf("==========\n");
	printf("Pilih Menu = ");
	scanf("%d",&menu);
	
	if (menu==1){
		a=1;
		printf("Berapa Data = ");
		scanf("%d",&n);
		printf("\n");
		while(!(a>n)){
			printf("Nama Ke-%d = ",a);
			scanf("%s",&nama[a]);
			printf("NPM Ke-%d  = ",a);
			scanf("%d",&npm[a]);
			printf("\n");
			a++;
		}
		system("cls");
		goto menu;
	}
	else if (menu==2){
		a=1;
		while(!(a>n)){
			if (npm[a]!=0){
				printf("Data %d\n",a);
				printf("Nama = %s\n",nama[a]);
				printf("NPM = %d\n",npm[a]);
				printf("\n");
			}
			else{
				
			}
			a++;
		}
		getch();
		system("cls");
		goto menu;
	}
	else if (menu==3){
		search:;
		a=1;
		printf("NPM Yang Dicari : ");
		scanf("%d",&search);
		while (!(a>n)){
			if (npm[a]==search){
				printf("Data %d\n",a);
				printf("Nama = %s\n",nama[a]);
				printf("NPM = %d",npm[a]);
				a=a+100;
				nosearch=1;
			}
			else{
				
			}
			a++;
		}
		if (nosearch==1){
			
		}
		else{
			printf("Data Tidak Ada, Tekan Apa Saja Untuk Mengulangi Pencarian\n\n");
			getch();
			goto search;
		}
		getch();
		system("cls");
		goto menu;
	}
	else if (menu==4){
		a=1;
		do {
			printf("Berapa Data = ");
			scanf("%d",&delete);
		}
		while (delete>n);
		while (!(a>delete)){
			printf("Data Ke = ");
			scanf("%d",&hapus);
			npm[hapus]=0;
			a++;
		}
		getch();
		system("cls");
		goto menu;
		
	}
	else if (menu==5){
		system("cls");
		goto exit;
	}
	else {
		system("cls");
		goto menu;
	}
	exit:;
	return 0;
}
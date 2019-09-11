#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int menu,a=1,harga[50],banyak[50],tunai[50],kembalian[50],b,c,io,r,anu,baris=0;
char nama[50][50], ukuran[50][50],key[50],line[255];
FILE*rico,*rico_history;
void input(); void view(); void update(); void delete(); void search(); void history();

int main(){
	
	rico=fopen("D:/Final Project.txt","r");
	
	printf("Menu : \n");
	printf("1. Input\n2. View\n3. Update\n4. Delete\n5. Search\n6. History\n7. Exit\n");
	printf("Pilih Menu = ");
 	scanf("%d",&menu);
 	printf("==================\n");
 	
 	if (menu==1){
		 input();
		 system("cls");
		 main();
	 }
	 else if(menu==2){
		 view();
		 getch();
		 system("cls");
		 main();
	 }
	 else if(menu==3){
		 update();
		 system("cls");
		 main();
	 }
	 else if(menu==4){
		 delete();
		 system("cls");
		 main();
	 }
	 else if(menu==5){
		 search();
		 getch();
		 system("cls");
		 main();
	 }
	 else if(menu==6){
		 history();
		 getch();
		 system("cls");
		 main();
	 }
	 else if(!(menu==7)){
		system("cls");
		main();
	 }
	fclose(rico);
	rico=fopen("D:/Final Project.txt","r");
	rico_history=fopen("D:/Final Project (History).txt","w+");
	while((r=getc(rico)) !=-1){
		fputc(r, rico_history);
	}
	fclose(rico_history);
	exit(EXIT_FAILURE);
}

void input(){
	printf("Data %d\n",a);
	printf("Nama Pelanggan       : ");
	scanf("%s",nama[a]);
	printf("Ukuran Foto          : ");
	scanf("%s",&ukuran[a]);
	printf("Harga Per Foto       : ");
	scanf("%d",&harga[a]);
	printf("Jumlah Foto          : ");
	scanf("%d",&banyak[a]);
	printf("Tunai                : ");
	scanf("%d",&tunai[a]);
	a++;
}

void view(){
	rico=fopen("D:/Final Project.txt","w+");
	b=1;
	while(!(b==a)){
		if(strcmp(nama[b],"1211")==0 && strcmp(ukuran[b],"1211")==0){
		}
		else{
			printf("Data %d\n",b);
			printf("Nama Pelanggan       : %s\n",nama[b]);
			printf("Ukuran Foto          : %s\n",ukuran[b]);
			printf("Harga Per Foto       : %d\n",harga[b]);
			printf("Jumlah Foto          : %d\n",banyak[b]);
			printf("Tunai                : %d\n", tunai[b]);
			printf("Kembalian            : ");
			fprintf(rico,"Data %d\n",b);
			fprintf(rico,"Nama Pelanggan       : %s\n",nama[b]);
			fprintf(rico,"Ukuran Foto          : %s\n",ukuran[b]);
			fprintf(rico,"Harga Per Foto       : %d\n",harga[b]);
			fprintf(rico,"Jumlah Foto          : %d\n",banyak[b]);
			fprintf(rico,"Tunai                : %d\n", tunai[b]);
			fprintf(rico,"Kembalian            : ");
			kembalian[b]=tunai[b]-(harga[b]*banyak[b]);
			if(kembalian[b]<0){
			   	kembalian[b]=kembalian[b]*(-1);
			   	printf("(*Uang anda kurang %d)",kembalian[b]);
			   	fprintf(rico,"(*Uang anda kurang %d)",kembalian[b]);
		   	}
			   	else{
			   	printf("%d",kembalian[b]);
			   	fprintf(rico,"%d",kembalian[b]);
			}
			printf("\n\n");
			fprintf(rico,"\n\n");
		}
		b++;
	}
	fclose(rico);
}

void update(){
	b=1;
	printf("Kata Kunci = ");
	scanf("%s",&key);
	while(!(b>a)){
		if(strcmp(key,nama[b])==0 || strcmp(key,ukuran[b])==0){
			printf("Apakah anda yakin ingin mengubah Data Ke-%d?\n0. No\n1. Yes\n",b);
			select_update:;
			printf("Pilih = ");
			scanf("%d",&io);
			if(io==1){
				printf("Data %d\n",b);
				printf("Nama Pelanggan       : ");
				scanf("%s",nama[b]);
				printf("Ukuran Foto          : ");
				scanf("%s",&ukuran[b]);
				printf("Harga Per Foto       : ");
				scanf("%d",&harga[b]);
				printf("Jumlah Foto          : ");
				scanf("%d",&banyak[b]);
				printf("Tunai                : ");
				scanf("%d",&tunai[b]);
				kembalian[b]=tunai[b]-(harga[b]*banyak[b]);
		   		system("cls");
		   		main();
			}
			else if(io==0){
				printf("Data tidak diubah...");
				getch();
		   		system("cls");
		   		main();
			}
			else{
				goto select_update;
			}
			}
		else{
		}
		b++;
	}
	printf("Data tidak ada...");
	getch();
}

void delete(){
	b=1;
	printf("Kata Kunci = ");
	scanf("%s",&key);
	while(!(b>a)){
		if(strcmp(key,nama[b])==0 || strcmp(key,ukuran[b])==0){
			printf("Apakah anda yakin ingin mengahapus Data Ke-%d?\n0. No\n1. Yes\n",b);
			select_delete:;
			printf("Pilih = ");
			scanf("%d",&io);
			if(io==1){
				strcpy(nama[b],"1211");
				strcpy(ukuran[b],"1211");
				printf("Data Berhasil dihapus...");
				getch();
		   		system("cls");
		   		main();
			}
			else if(io==0){
				printf("Data tidak dihapus...");
				getch();
		   		system("cls");
		   		main();
			}
			else{
				goto select_delete;
			}
			}
		else{
		}
		b++;
	}
	printf("Data tidak ada...");
	getch();
}

void search(){
	b=1;
	printf("Kata Kunci = ");
	scanf("%s",&key);
	while(!(b>a)){
		if(strcmp(key,nama[b])==0 || strcmp(key,ukuran[b])==0){
			printf("Data %d\n",b);
			printf("Nama Pelanggan       : %s\n",nama[b]);
			printf("Ukuran Foto          : %s\n",ukuran[b]);
			printf("Harga Per Foto       : %d\n",harga[b]);
			printf("Jumlah Foto          : %d\n",banyak[b]);
			printf("Tunai                : %d\n", tunai[b]);
			printf("Kembalian            : ");
			kembalian[b]=tunai[b]-(harga[b]*banyak[b]);
			if(kembalian[b]<0){
			   	kembalian[b]=kembalian[b]*(-1);
			   	printf("(*Uang anda kurang %d)",kembalian[b]);
			}
			else{
			   	printf("%d",kembalian[b]);
		   	}
		   	getch();
		   	system("cls");
		   	main();
			}
		else{
		}
		b++;
	}
	printf("Data tidak ada...");
}

void history(){
	rico_history=fopen("D:/Final Project (History).txt","r");
	if(!rico_history){
		printf("History tidak ada...");
		getch();
		system("cls");
		main();
	}
	while(fgets(line,255,rico_history))baris++;
	if(baris==0||baris==1){
		printf("History kosong...");
		getch();
		system("cls");
		main();
	}
	fclose(rico_history);
	rico_history=fopen("D:/Final Project (History).txt","r");
	while((r=getc(rico_history))!=-1){
		printf("%c",r);
	}
}
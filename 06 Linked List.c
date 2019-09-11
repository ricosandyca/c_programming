/*
Nama  : Rico Sandyca Novenza
NPM   : 1634010052
kelas : B
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
  char nama[50];
  char npm[50];
  char kelas[50];
  struct data *node;
} *head, *tail, *current;

char nama[50], npm[50], kelas[50], nama2[10], npm2[10], kelas2[1];
int menu, a;

int main(){
  printf("+----------------+\n|  Linked List:  |\n+----------------+\n|    1. Add      |\n|    2. Read     |\n|    0. Exit     |\n+----------------+\n");
  printf("\nMenu = ");
  scanf("%d",&menu);
  fflush(stdin);
  if(menu==1){
    system("cls");
	add();
  }
  else if(menu==2){
    system("cls");
    read();
  }
  else if(menu==0){
    exit(EXIT_FAILURE);
  }
  else{
    system("cls");
    main();
  }
}

void add(){
  char spasi[10] = "          ";
  printf("+-------------------------------------------------+\n|                      ADD                        |\n+-------------------------------------------------+\n\n");
  printf("  TAMBAH DATA\n");
  printf("  -------------\n\n");
  printf("  Nama     =   ");
  scanf("%[^\n]",&nama);
  strcat(nama,spasi);
  getchar();
  printf("  NPM      =   ");
  scanf("%[^\n]",&npm);
  getchar();
  strcat(npm,spasi);
  printf("  Kelas    =   ");
  scanf("%[^\n]",&kelas);
  getchar();
  strcat(kelas,spasi);
  current = (struct data*)malloc(sizeof(struct data));
  strcpy(current->nama, nama);
  strcpy(current->npm, npm);
  strcpy(current->kelas, kelas);
  if(head == NULL){
    head = current;
    tail = current;
  }
  else{
    tail->node = current;
    tail = current;
  }
  tail->node = NULL;
  printf("\n\n  BERHASIL!\n");
  printf("  -------------\n\n");
  getch();
  system("cls");
  main();
}

void read(){
  current = head;
  printf("+-------------------------------------------------+\n|                      READ                       |\n+-------------------------------------------------+\n\n");
  if(current == NULL){
    printf("-- Data Kosong --\n");
  }
  else{
    a = 1;
    printf("+------++---------------++---------------++-------+\n|  NO  ||     NAMA      ||     NPM       || KELAS |\n+------++---------------++---------------++-------+\n");
    while(current != NULL){
      strncpy(nama2, current->nama, 10);
      strncpy(npm2, current->npm, 10);
      strncpy(kelas2, current->kelas, 1);
      printf("|  %02d  |",a);
      printf("|  %s   |",nama2);
      printf("|  %s   |",npm2);
      printf("|   %s   |",kelas2);
      printf("\n");
      current = current->node;
      a++;
  	}
    printf("---------------------------------------------------");
  }
  getch();
  system("cls");
  main();
}

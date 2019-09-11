/*
Nama  : Rico Sandyca Novenza
NPM   : 1634010052
kelas : B
*/

#include <stdio.h>

void main(){
  int a, b, c, n, prima;
  printf("+------------------------+\n|  Deret Bilangan Prima  |\n+------------------------+\n");
  printf("\nBanyak deret  =  ");
  scanf("%d",&n);
  printf("\n[  ");
  anuan(1, b, 0, n, prima);
  printf("]\n");
  getch();
}

void anuan(int a, int b, int c, int n, int prima){
  if(!(a>n && c==n)){
    prima = 0;
    b = 1;
    prima = anuan2(a, b, prima);
    if(!(prima>2 || prima==1)){
      printf("%d  ",a);
      c++;
    }
    anuan(a+1, b, c, n, prima);
  }
}

int anuan2(int a, int b, int prima){
  if(!(b>a)){
    if(a%b==0){
      prima++;
    }
    prima = anuan2(a, b+1, prima);
  }
  return (prima);
}

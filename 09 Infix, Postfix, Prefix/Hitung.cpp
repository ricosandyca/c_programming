/*
Nama  : Rico Sandyca Novenza
NPM   : 1634010052
Kelas : B
Judul : Hasil Operasi
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

bool isHuruf(char anu);
bool isOperator(char anu);
int prioritas(char anu);
void push(char anu2);
char peek();
void pop();

struct stack{
  char data;
  struct stack *next;
}*head, *temp;

string infix;

int main(){
  double satu, dua, tiga;
  int a = 0, n = 0, b = 0, c, sudah;
  cout<<"Infix = ";
  getline(cin,infix);
  cout<<"Postfix = ";
  temp = head;
  char anuan[infix.length()];
  while(!(a>infix.length())){
    if(isHuruf(infix[a])){
      cout<<infix[a]<<" ";
      anuan[b] = infix[a]; b++;
    }
    else if(isOperator(infix[a])){
      if(n==0 || prioritas(infix[a]) > prioritas(peek())){
        push(infix[a]); n++;
      }
      else{
        while(prioritas(infix[a])<=prioritas(peek())){
          cout<<peek()<<" ";
          anuan[b] = peek(); b++;
          pop(); n--;
        }
        push(infix[a]); n++;
      }
    }
    else if(infix[a]=='('){
      push(infix[a]); n++;
    }
    else if(infix[a]==')'){
      while(!(peek()=='(')){
        cout<<peek()<<" ";
        anuan[b] = peek(); b++;
        pop(); n--;
      }
      pop(); n--;
    }
    a++;
  }
  while(!(n<=0)){
    if(!(peek()=='(')){
      cout<<peek()<<" ";
      anuan[b] = peek(); b++;
    }
    pop(); n--;
  }
  cout<<endl<<"Hasil = ";
  b--;
  a = 0;
  while(!(a>b)){
    if(isHuruf(anuan[a])){
      push(anuan[a]); n++;
    }
    else if(isOperator(anuan[a])){
      if(sudah==1){
        dua = peek();
        pop();
      }
      else{
        dua = peek() - 48;
        pop();
      }
      satu = peek() - 48;
      pop();
      switch(anuan[a]){
        case '^':
          tiga = satu;
          c = 1;
          while(!(c>(dua-1))){
            tiga = tiga * satu;
            c++;
          }
          break;
        case '*': tiga = satu * dua; break;
        case '/':
        case ':': tiga = satu / dua; break;
        case '+': tiga = satu + dua; break;
        case '-': tiga = satu - dua; break;
        default: break;
      }
      push(tiga);
      sudah++;
    }
    a++;
  }
  cout<<tiga;
}

int prioritas(char anu){
  if(anu=='+' || anu=='-'){
    return 1;
  }
  else if(anu=='*' || anu=='/' || anu==':'){
    return 2;
  }
  else if(anu=='^'){
    return 3;
  }
  else{
    return 0;
  }
}

bool isOperator(char anu){
  if(anu=='+' ||anu=='-' || anu=='*' || anu==':' || anu=='/' || anu=='^'){
    return true;
  }
  else{
    return false;
  }
}

bool isHuruf(char anu){
  if((anu>='0' && anu<='9') || (anu>='a' && anu<='z') || (anu>='A' && anu<='Z')){
    return true;
  }
  else{
    return false;
  }
}

void push(char anu2){
  temp = (struct stack*)malloc(sizeof(struct stack));
  temp->data = anu2;
  if(head==NULL){
    head = temp;
  }
  else{
    temp->next = head;
    head = temp;
  }
}

char peek(){
  return (head->data);
}

void pop(){
  temp = head;
  if(head->next==NULL){
    free(temp);
  }
  else{
    head = head->next;
    free(temp);
  }
}

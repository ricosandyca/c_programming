/*
Nama  : Rico Sandyca Novenza
NPM   : 1634010052
Kelas : B
Judul : Konversi Infix to Postfix
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
  int a = 0, n = 0;
  cout<<"Infix = ";
  getline(cin,infix);
  cout<<"Postfix = ";
  temp = head;
  while(!(a>infix.length())){
    if(isHuruf(infix[a])){
      cout<<infix[a]<<" ";
    }
    else if(isOperator(infix[a])){
      if(n==0 || prioritas(infix[a]) > prioritas(peek())){
        push(infix[a]); n++;
      }
      else{
        while(prioritas(infix[a])<=prioritas(peek())){
          cout<<peek()<<" ";
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
        pop(); n--;
      }
      pop(); n--;
    }
    a++;
  }
  while(!(n<=0)){
    if(!(peek()=='(')){
      cout<<peek()<<" ";
    }
    pop(); n--;
  }
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

/*
Sumber algoritma:
http://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/
*/

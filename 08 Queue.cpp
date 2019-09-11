#include <iostream>
#include <stdlib.h>
using namespace std;

void enqueue(string anu);
string dequeue();
bool isEmpty();
bool isFull();

struct queue{
  string data;
  queue *next;
}*head, *tail, *temp;

int main(){
  enqueue("A");
  enqueue("B");
  enqueue("C");
  dequeue();
  enqueue("D");
  enqueue("E");
  dequeue();
  dequeue();
  while(!(isEmpty())){
    cout<<dequeue()<<endl;
  }
}

void enqueue(string anu){
  temp = (struct queue*)malloc(sizeof(struct queue));
  temp->data = anu;
  if(head==NULL){
    head = temp;
    tail = temp;
  }
  else{
    tail->next = temp;
    tail = temp;
  }
  tail->next = NULL;
}

string dequeue(){
  string tampung;
  temp = head;
  if(head==NULL){
  }
  else{
    tampung = temp->data;
    if(head->next==NULL){
      head = NULL;
      free(temp);
    }
    else{
      head = head->next;
      free(temp);
    }
    return tampung;
  }
}

bool isEmpty(){
  if(head==NULL){
    return true;
  }
  else{
    return false;
  }
}

bool isFull(){
  int a = 1, muatan = 3;
  temp = head;
  while(!(temp->next==NULL)){
    a++;
    temp = temp->next;
  }
  if(a>=muatan){
    return true;
  }
  else{
    return false;
  }
}

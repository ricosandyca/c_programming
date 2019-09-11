#include <iostream>
#include <stdlib.h>
using namespace std;

struct family{
  string nama;
  family *pasangan, *anak1, *anak2, *ortu1, *ortu2;
}*temp, *root;

void menu();
void input(family *temp, string data);
void view(family *temp);
void search();
void searchpasangan(family *temp, string data);
void searchanak(family *temp, string data);
void searchortu(family *temp, string data);

int main(){
  root = (struct family*)malloc(sizeof(struct family));
  root->anak1 = NULL;
  root->anak2 = NULL;
  root->pasangan = NULL;
  root->ortu1 = NULL;
  root->ortu2 = NULL;
  menu();
  return 0;
}

void menu(){
  string data;
  int pilih;
  cout<<"+-------------------------+"<<endl;
  cout<<"|                         |"<<endl;
  cout<<"|      FINAL PROJECT      |"<<endl;
  cout<<"|                         |"<<endl;
  cout<<"+-------------------------+"<<endl;
  cout<<"1. INPUT"<<endl<<"2. VIEW"<<endl<<"3. SEARCH"<<endl<<"4. EXIT"<<endl<<"Menu = ";
  cin>>pilih;
  system("cls");
  switch(pilih){
    case 1:
      cout<<"INPUT"<<endl<<"-------------"<<endl;
      cout<<"Root = ";
      cin>>data;
      input(root, data);
      cout<<endl;
      system("pause");
      break;
    case 2:
      cout<<"VIEW"<<endl<<"-------------"<<endl;
      view(root);
      cout<<endl;
      system("pause");
      break;
    case 3:
      search();
      break;
    case 4:
      exit(EXIT_FAILURE);
      break;
    default:
      menu();
      break;
  }
  system("cls");
  menu();
}

void search(){
  int pilih;
  string data;
  cout<<"SEARCH"<<endl<<"-------------"<<endl;
  cout<<"1. COUPLE"<<endl<<"2. CHILD"<<endl<<"3. PARENT"<<endl<<"4. BACK"<<endl<<"Menu = ";
  cin>>pilih;
  system("cls");
  switch(pilih){
    case 1:
      cout<<"SEARCH COUPLE"<<endl<<"-------------"<<endl;
      cout<<"Keyword = ";
      cin>>data;
      searchpasangan(root, data);
      cout<<endl;
      system("pause");
      break;
    case 2:
      cout<<"SEARCH CHILD"<<endl<<"-------------"<<endl;
      cout<<"Keyword = ";
      cin>>data;
      searchanak(root, data);
      cout<<endl;
      system("pause");
      break;
    case 3:
      cout<<"SEARCH PARENT"<<endl<<"-------------"<<endl;
      cout<<"Keyword = ";
      cin>>data;
      searchortu(root, data);
      cout<<endl;
      system("pause");
      break;
    case 4: menu(); break;
    default: ;
  }
  system("cls");
  search();
}

void input(family *temp, string data){
  int test;
  temp->nama = data;
  temp->pasangan = NULL;
  temp->anak1 = NULL;
  temp->anak2 = NULL;
  temp->ortu1 = NULL;
  temp->ortu2 = NULL;
  cout<<"Pasangan ? ";
  cin>>test;
  if(test==1){
    cout<<"Nama Pasangan = ";
    cin>>data;
    temp->pasangan = (struct family*)malloc(100 * sizeof(struct family));
    temp->pasangan->nama = data;
    temp->pasangan->pasangan = temp;
    temp->pasangan->anak1 = NULL;
    temp->pasangan->anak2 = NULL;
    temp->pasangan->ortu1 = NULL;
    temp->pasangan->ortu2 = NULL;
    cout<<"Anak ? ";
    cin>>test;
    if(test==1){
      cout<<"Nama Anak = ";
      cin>>data;
      temp->anak1 = (struct family*)malloc(100 * sizeof(struct family));
      input(temp->anak1, data);
      temp->anak1->ortu1 = temp;
      temp->anak1->ortu2 = temp->pasangan;
      temp->pasangan->anak1 = temp->anak1;
      cout<<"Anak 2 ? ";
      cin>>test;
      if(test==1){
        cout<<"Nama Anak = ";
        cin>>data;
        temp->anak2 = (struct family*)malloc(100 * sizeof(struct family));
        input(temp->anak2, data);
        temp->anak2->ortu1 = temp;
        temp->anak2->ortu2 = temp->pasangan;
        temp->pasangan->anak2 = temp->anak2;
      }
    }
  }
}

void view(family *temp){
  cout<<temp->nama<<endl;
  if(temp->pasangan != NULL){
    cout<<temp->pasangan->nama<<endl;
    if(temp->anak1 != NULL){
      view(temp->anak1);
      if(temp->anak2 != NULL){
        view(temp->anak2);
      }
    }
  }
}

void searchpasangan(family *temp, string data){
  if(temp->nama == data){
    if(temp->pasangan != NULL){
      cout<<endl;
      cout<<"PASANGAN = "<<temp->pasangan->nama<<endl;
    }
  }
  else{
    if(temp->pasangan != NULL){
      if(temp->pasangan->nama == data){
        cout<<endl;
        cout<<"PASANGAN = "<<temp->pasangan->pasangan->nama<<endl;
      }
      if(temp->anak1 != NULL){
        searchpasangan(temp->anak1, data);
        if(temp->anak2 != NULL){
          searchpasangan(temp->anak2, data);
        }
      }
    }
  }
}

void searchanak(family *temp, string data){
  if(temp->anak1 == NULL || temp->pasangan->anak1 == NULL){
  }
  else if(temp->nama == data || temp->pasangan->nama == data){
    if(temp->anak1 != NULL){
      cout<<endl;
      cout<<"ANAK 1 = "<<temp->anak1->nama<<endl;
      if(temp->anak2 != NULL){
        cout<<"ANAK 2 = "<<temp->anak2->nama<<endl;
      }
    }
  }
  else{
    if(temp->anak1 != NULL){
      searchanak(temp->anak1, data);
      if(temp->anak2 != NULL){
        searchanak(temp->anak2, data);
      }
    }
  }
}

void searchortu(family *temp, string data){
  if(temp->nama == data){
    cout<<endl;
    if(temp == root){
      cout<<data<<" ADALAH ROOT"<<endl;
    }
    else{
      cout<<"ORANG TUA 1 = "<<temp->ortu1->nama<<endl;
      cout<<"ORANG TUA 2 = "<<temp->ortu2->nama<<endl;
    }
  }
  else{
    if(temp->anak1 != NULL){
      searchortu(temp->anak1, data);
      if(temp->anak2 != NULL){
        searchortu(temp->anak2, data);
      }
    }
  }
}

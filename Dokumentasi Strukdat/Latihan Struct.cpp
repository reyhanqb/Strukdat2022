#include <iostream>

using namespace std;

// deklarasi single linked list
struct biodata{

  // komponen / member
  string nama, pekerjaan;
  int umur;

  biodata *next;

};

biodata *head, *tail, *current, *newNode, *del, *before;

// create single linked list
void createSingleLinkedList(string nama, string pekerjaan, int umur){
  head = new biodata();
  head->nama = nama;
  head->pekerjaan = pekerjaan;
  head->umur = umur;
  head->next = NULL;
  tail = head;
}


// print single linked list
int countSingleLinkedList(){
  current = head;
  int jumlah = 0;
  while( current != NULL ){
    jumlah++;
    current = current->next;
  }
  return jumlah;
}

// Remove First
void removeHead(){
  del = head;
  head = head->next;
  delete del;
}

// Remove Last
void removeTail(){
  del = tail;
  current = head;
  while( current->next != tail ){
    current = current->next;
  }
  tail = current;
  tail->next = NULL;
  delete del;
}

// remove middle
void removeMiddle(int pos){
  int nomor = 1;
  if( pos < 1 || pos > countSingleLinkedList() ){
    cout << "error" << endl;
  }else if( pos == 1){
    cout << "error" << endl;
  }else{
    current = head;
    while( nomor <= pos ){
      if( nomor == pos-1 ){
        before = current;
      }
      if( nomor == pos ){
        del = current;
      }
      current = current->next;
      nomor++;
    }
    before->next = current;
    delete del;
  }
}

// ubahAwal Single linked list
void changeHead(string nama, string pekerjaan, int umur){
  head->nama = nama;
  head->pekerjaan = pekerjaan;
  head->umur = umur;
}

// tambahAwal Single linked list
void addFirst(string nama, string pekerjaan, int umur){
  newNode = new biodata();
  newNode->nama = nama;
  newNode->pekerjaan = pekerjaan;
  newNode->umur = umur;
  newNode->next = head;
  head = newNode;
}

// tambahAkhir Single linked list
void addTail(string nama, string pekerjaan, int umur){
  newNode = new biodata();
  newNode->nama = nama;
  newNode->pekerjaan = pekerjaan;
  newNode->umur = umur;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

// tambah tengah single linked list
void addMiddle(string nama, string pekerjaan, int umur, int pos){
  if( pos < 1 || pos > countSingleLinkedList() ){
    cout << "error" << endl;
  }else if( pos == 1){
    cout << "error" << endl;
  }else{
    newNode = new biodata();
    newNode->nama = nama;
    newNode->pekerjaan = pekerjaan;
    newNode->umur = umur;

    // tranversing
    current = head;
    int nomor = 1;
    while( nomor < pos - 1 ){
      current = current->next;
      nomor++;
    }
    newNode->next = current->next;
    current->next = newNode;
  }
}

// ubahAkhir Single linked list
void changeTail(string nama, string pekerjaan, int umur){
  tail->nama = nama;
  tail->pekerjaan = pekerjaan;
  tail->umur = umur;
}

// ubah Tengah Single linked list
void changeMiddle(string nama, string pekerjaan, int umur, int pos){
  if( pos < 1 || pos > countSingleLinkedList() ){
    cout << "error" << endl;
  }else if( pos == 1 || pos == countSingleLinkedList() ){
    cout << "error" << endl;
  }else{
    current = head;
    int nomor = 1;
    while( nomor < pos ){
      current = current->next;
      nomor++;
    }
    current->nama = nama;
    current->pekerjaan = pekerjaan;
    current->umur = umur;
  }
}

// print single linked list
void printSingleLinkedList(){
  countSingleLinkedList();
  current = head;
  while( current != NULL ){
    cout << "Nama  : " << current->nama << endl;
    cout << "Pekerjaan  : " << current->pekerjaan << endl;
    cout << "Umur : " << current->umur << endl;

    current = current->next;
  }
}

int main(){

  createSingleLinkedList("Jono", "Nelayan", 28);

  printSingleLinkedList();

  cout << "print out fungsi addFirst" << endl;

  addFirst("Joni", "Masinis", 34);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  cout << "print out fungsi addTail" << endl;

  addTail("Adi", "Petani", 24);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  cout << "remove head" << endl;

  removeHead();

  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  cout << "print out fungsi addTail" << endl;

  addTail("Noni", "Atlet", 19);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  cout << "print out fungsi removeTail" << endl;

  removeTail();

  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  cout << "print out fungsi changeHead" << endl;

  changeHead("Sarah", "Pilot", 25);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  cout << "print out fungsi addMiddle" << endl;

  addMiddle("Ahmad", "Guru", 30, /*posisi akan diinsert*/ 2);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  cout << "remove middle" << endl;

  removeMiddle(5);

  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  cout << "print out fungsi changeMiddle" << endl;

  changeMiddle("Kiki", "Koki", 27, 2);

  printSingleLinkedList();
  
}

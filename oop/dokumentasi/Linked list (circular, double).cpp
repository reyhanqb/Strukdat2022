// Tugas 2 No 1
#include <bits/stdc++.h>

using namespace std;

struct Node {
 	int data;
 	struct Node *next;
 	struct Node *prev;
};

Node *head, *tail;
 
void init(){

	head = NULL;
	tail = NULL;
}

void insertHead(int data){
 	struct Node* newData;
 	newData = new Node;

 	if (head==NULL) {
 	 	
 	 	head=newData;
 	 	newData->prev = NULL;
 	 	newData->next = NULL;
 	 	newData->data = data;
 	 	tail=newData;
 	 } 
 	 else {
 	 	
 	 	newData->next = head;
 	 	newData->data = data;
 	 	newData->prev = NULL;
 	 	head->prev = newData;
 	 	head = newData; 
 	 }
}

void insertTail(int data){

 	struct Node* newData;
 	newData = new Node;
 	newData->data = data;
 	
 	if (head==NULL) {
 	 	head=newData;
 	 	newData->prev = NULL;
 	 	newData->next = NULL;
 	 	newData->data = data;
 	 	tail=newData;
 	 } 
 	 else {
 	 	
 	 	newData->prev = tail;
 	 	tail->next = newData;
 	 	newData->next = NULL;
 	 	tail = newData; 
 	 }
}

void insertAfter(int before, int data){
	struct Node* newData;
	newData = new Node;
	struct Node* temp;
	temp = head;
	if (head==NULL)
	{
		//Case kalau headnya belum ada (isi node masih kosong)
		cout << "error" << endl;
		return;
	}
	if (head==tail){
		//Case kalau value before tidak sesuai input user
		if (head->data != before){
			cout << "error" << endl;
			return;
		}
		newData->data = data;
		head->next = newData;
		newData->next = NULL;
		head->prev = NULL;
		newData->prev = head;
		tail = newData;
		return;
	}
	if (tail->data == data)
	{
		newData->next = NULL;
		newData->prev = tail;
		tail->next = newData;
		tail = newData;
		return;
	}
	while(temp->data != before){
		temp = temp->next;
		if (temp == NULL)
		{
			cout << "element tidak ada?" <<endl;
			return;
		}
	}
	newData->next = temp->next;
	newData->prev = temp;
	newData->data = data;
	temp->next->prev = newData;
	temp->next = newData;
}

void printList(){
	struct Node* temp;
	temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp=temp->next;
	}
}

int main()
{
	init();
	insertHead(9);
	insertTail(3);
	insertAfter(9, 6);
	insertAfter(6, 8);
	printList();
	return 0;
}

// Tugas 2 No 2
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

Node *last, *temp, *p;

void createList(int data)
{

	if (last != NULL){
	    return;    
	}
	
	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = data;
	last = temp;
	last->next = last;

}

void addHead(int data)
{
	if (last == NULL){
		return createList(data);
	}

	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = last->next;
	last->next = temp;

}

void addEnd(int data)
{
	if (last == NULL)
		return createList(data);

	
	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = data;
	temp->next = last->next;
	last->next = temp;
	last = temp;
}

void insertAfter(int data, int item)
{
	if (last == NULL){
		return;
	}
	p = last->next;

	do {
		if (p->data == item) {
			temp = (struct Node*)malloc(sizeof(struct Node));
			temp->data = data;
			temp->next = p->next;
			p->next = temp;
			if (p == last)
				last = temp;
			return;
		}
		p = p->next;
	} 
	while (p != last->next);
}

void printList()
{
	if (last == NULL) {
		cout << "error" << endl;
		return;
	}

	p = last->next;
	do {
		cout << p->data << " ";
		p = p->next;
	} 
	while (p != last->next);
}

int main()
{
	struct Node* last = NULL;
	createList(7);
	addHead(5);
	addHead(1);
	addEnd(3);
	insertAfter(1, 8);

	printList();
	return 0;
}

//Tugas 2 No 3
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

Node *last, *temp, *p;

void createList(int data)
{

	if (last != NULL){
	    return;    
	}
	
	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = data;
	last = temp;
	last->next = last;

}

void addHead(int data)
{
	if (last == NULL){
		return createList(data);
	}

	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = last->next;
	last->next = temp;

}

void addEnd(int data)
{
	if (last == NULL)
		return createList(data);

	
	temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = data;
	temp->next = last->next;
	last->next = temp;
	last = temp;
}

void insertAfter(int data, int item)
{
	if (last == NULL){
		return;
	}
	p = last->next;

	do {
		if (p->data == item) {
			temp = (struct Node*)malloc(sizeof(struct Node));
			temp->data = data;
			temp->next = p->next;
			p->next = temp;
			if (p == last)
				last = temp;
			return;
		}
		p = p->next;
	} 
	while (p != last->next);
}

void printList()
{
	if (last == NULL) {
		cout << "error" << endl;
		return;
	}

	p = last->next;
	do {
		cout << p->data << " ";
		p = p->next;
	} 
	while (p != last->next);
}

int main()
{
	struct Node* last = NULL;
	createList(7);
	addHead(5);
	addHead(1);
	addEnd(3);
	insertAfter(1, 8);

	printList();
	return 0;
}


#include <bits/stdc++.h>
#define MAX 10
using namespace std;

struct _queue{
    int top;
    int bottom;
    string data[MAX];
}queue1, queue2, queue3;



void initQueue(_queue *q) {
    q->top = -1;
    q->bottom = -1;
}
bool isFull(_queue *q) {
    return (q->bottom == MAX-1);
}

bool isEmpty(_queue *q) {
    return (q->top == -1 && q->bottom == -1);
}

void push(_queue *q, string data) {
    if (isFull(q)) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty(q)) {
            q->top = 0;
        }
        q->bottom++;
        q->data[q->bottom] = data;
    }
}
void pop(_queue *q) {
    if (isEmpty(q)) {
        cout << "Antrian sudah kosong" << endl;
    } 
    else {
        if (q->top == q->bottom) {
            initQueue(q);
        } else {
            q->top++;
        }
    }
}

void printStack(_queue *q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = q->top; i <= q->bottom; i++) {
            cout << q->data[i] << " " << "urutan ke- "<< i+1 << endl;
        }
        cout << endl;
    }
}



int main(){
    
    int n;
    string command;
    string data;
    
    initQueue(&queue1);
    initQueue(&queue2);
    initQueue(&queue3);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "masuk") {
            cin >> data;
            if((&queue1)->bottom <= (&queue2)->bottom && (&queue1)->bottom <= (&queue3)->bottom){
                push(&queue1, data);
            }
            else if((&queue2)->bottom <= (&queue1)->bottom && (&queue2)->bottom <= (&queue3)->bottom){
                push(&queue2, data);
            }
            else if((&queue3)->bottom <= (&queue1)->bottom && (&queue3)->bottom <= (&queue2)->bottom){
                push(&queue3, data);
            }
        } 
        else if (command == "layani") {
            pop(&queue1);
            pop(&queue2);
            pop(&queue3);
        }
    }
 
    printStack(&queue1);
    cout << "antrian ini dilayani teller 1" << endl;
    printStack(&queue2);
    cout << "antrian ini dilayani teller 2" << endl;
    printStack(&queue3);
    cout << "antrian ini dilayani teller 3" << endl;

}
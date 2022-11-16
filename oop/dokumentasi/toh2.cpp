#include <bits/stdc++.h> 

using namespace std;


struct Stack { 
   int size; 
   int top;  
   int *arr;
};

 Stack *asal, *tujuan, *temp;

Stack* init(int size) 
    {
        Stack* stack= new Stack;
        stack->size =size;
        stack->top =-1; 
        stack->arr = new int[size];
        return stack;
    }

bool isFull(Stack* stack) 
    { 
       if(stack->top == stack->size - 1)
          return true;
       else
         return false;
     }
     
bool isEmpty(Stack* stack) 
    { 
       if(stack->top == -1)
         return true;
      else
        return false; 
    }
void push(Stack* stack, int element) 
   { 
      if(isFull(stack)) 
         return; 

      stack->arr[++stack->top]= element; 
   }

int pop(Stack* stack) 
   { 
        if(isEmpty(stack)) 
           return -1;
           
        return(stack->arr[stack->top--]); 
    }

void _print(int Cakram, char asalCakram, char tujuanCakram) 

   {   

       cout<<" Pindahkan cakram " << Cakram <<" "<<"dari tiang '" <<asalCakram<< "' ke tiang '" << tujuanCakram << "'"<< endl;


   } 

void pindahkanCakram(char s, char d) 
   { 
      int top1= pop(asal); 
      int top2 = pop(tujuan); 
      if (top1 == -1) 
       { 
           push(asal,top2); 
           _print(top2, d, s); 
       } 
      else if (top2 ==-1) 

      { 
              push( tujuan,top1); 
              _print(top1, s, d); 
      } 
      else if (top1 >top2) 
      { 
              push(asal, top1);
              push(asal, top2); 
              _print(top2, d, s); 
       } 
      else
       { 
             push( tujuan,top2); 
             push( tujuan,top1); 
             _print(top1, s, d); 

       } 
 } 

void TowerOfHanoi(int jumlahCakram) 

    {  
            char s = 'a', d = 'b', a = 'c'; 
            
            if (jumlahCakram % 2== 0) 
            {
                        char var =d;
                        d =a;
                        a =var; 
            } 

            int pindah =pow(2, jumlahCakram) - 1; 
            for (int i =jumlahCakram; i >= 1; i--) 
            {
                push(asal,i); 
            }
            
            for (int i = 1; i <= pindah; i++) 
            { 
                if (i % 3== 0)  
                      pindahkanCakram(a, d); 
               else if (i% 3 == 2) 
                      pindahkanCakram(s, a); 
               else if (i% 3 == 1) 
                      pindahkanCakram(s, d); 
            } 
            free(temp);
    }  

    int main() 

    { 
            int jumlahCakram;
            cout << "Masukkan jumlah cakram" << endl;
            cin >> jumlahCakram;
                         
           
            asal = init(jumlahCakram); 
            temp = init(jumlahCakram); 
            tujuan = init(jumlahCakram);   

            TowerOfHanoi(jumlahCakram);
     
            return 0;
    }
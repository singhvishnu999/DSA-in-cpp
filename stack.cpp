#include <iostream>
using namespace std;
struct stack{
    int size;
    int top ;
    int arr[];
};
int isEmpty(struct stack *sp);
int isFull(struct stack *sp);
void display(struct stack *sp);
void push(struct stack *sp, int data);
void pop(struct stack *sp);
int peek(struct stack *ptr);

int isEmpty(struct stack *sp){
    if(sp -> top == -1){
       return 1;
    }
    return 0;
}

int isFull(struct stack *sp){
    if(sp-> top >= sp->size-1){
        cout<<"sack is overfllow"<<endl;
        return 1;
    }
    else{
        cout<<"stack can take item"<<endl;
        return 0;
    }
}

void display(struct stack *sp)
{
    for(int i = 0; i<=sp->top;i++){
        cout<<sp->arr[i]<<" ";
    }
}

void push(struct stack *sp, int data)
{
    if(sp-> top == sp->size-1){
        cout<<"stack is overflow"<<endl;
       
        }
        else{
           sp -> top++;
       sp->arr[sp -> top] = data;  
        }
}

void pop(struct stack *sp)
{
    if(isEmpty(sp)){
        cout<<"stack UNDERFLOW"<<endl;
    }
    else{
        sp -> top--;
    }
}

int peek(struct stack *ptr){
    if(isEmpty(ptr)){
        return -1;
    }
    else{
    int data = ptr->arr[ptr -> top] ;
    return data;
    }
}

int main(){
    struct stack *sp = new struct stack;
    sp->size = 10;
    sp -> top = -1;
    push(sp,2);
    push(sp,23);
    push(sp,54);
    push(sp,34);
    push(sp,86);
    push(sp,64);
    push(sp,14);
    push(sp,96);
    display(sp);

    cout<<endl<<"After deletion element is"<<endl;
    pop(sp);
    pop(sp);
    display(sp);
    
    cout<<endl<<"the peek of the element is ";
    cout<<peek(sp);
    delete(sp);
    
    return 0;
}
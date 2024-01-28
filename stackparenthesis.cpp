#include <iostream>
using namespace std;

class stack{
    public:
    int size;
    int top;
    char arr[];

    int isEmpty(){
        if(top == -1)
        {
            return 1;
        }
        return 0;
    }
    int isFull(){
        if(top == size-1){
            return 1;
        }
        return 0;
    }
    char stacktop()
    {
        return arr[top];
    }

    void push(char data){
        if(top == size-1)
        {
            cout<<"stack is full";
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    char pop(){
        char data;
        if(top == -1){
            cout<<"stack is underflow";
        }
        else{
            data = arr[top];
            top--;
        }
        return data;
    }

};

 int parenthesis(char exp[]){
    class stack *sp = new stack;
    sp -> size = 100;
    sp -> top = -1;
    sp -> arr[sp->size];
    for(int i =0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        {
            sp->push('(');
        }
        else if(exp[i] == ')')
        {
            if(sp->isEmpty())
            {
                return 0;
            }
            sp->pop();
        }
    }

    if(sp->isEmpty())
    {
        return 1;
    }
    else{
        return 0;
    }
 }

 int main(){
    char exp[] = "8*2+3)/4()";
    if(parenthesis(exp)){
        cout<<"parenthesis is matching ";
    }
    else{
        cout<<"parenthesis is not matching ";
    }

    return 0;
 }
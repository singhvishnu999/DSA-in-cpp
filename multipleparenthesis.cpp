#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int top;
    char arr[];

    int isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }
    int isFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        return 0;
    }

    void push(char data)
    {
        if (top == size - 1)
        {
            cout << "stack is full";
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    char pop()
    {
        char data;
        if (top == -1)
        {
            cout << "stack is underflow";
        }
        else
        {
            data = arr[top];
            top--;
        }
        return data;
    }
};

int matching(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '{' && b == '}')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesis(char exp[])
{
    class stack *sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr[sp->size];
    char pop_ele;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            sp->push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (sp->isEmpty())
            {
                return 0;
            }
            pop_ele = sp->pop();
            if (!matching(pop_ele, exp[i]))
            {
                return 0;
            }
        }
    }
    if (sp->isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char exp[] = "[8*(2+3)/4]";
    if (parenthesis2(exp))
    {
        cout << "parenthesis is matching ";
    }
    else
    {
        cout << "parenthesis is not matching ";
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;
class post
{
public:
    int size;
    int top;
    char *arr;

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
    void push(char ch)
    {
        if (isFull())
        {
            cout << "cannot push" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = ch;
        }
    }

    int pop()
    {
        char ch;
        if (isEmpty())
            cout << "cannot pop" << endl;
        else
        {
            ch = arr[top];
            top--;
        }
        return ch;
    }

    int stacktop()
    {
        return arr[top];
    }
};

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
    {
        return 0;
    }
}

char *postfix(string infix)
{
    class post *p = new post;
    p->top = -1;
    p->size = 100;
    p->arr = new char[100];
    char *postf = new char[infix.length() + 1];
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postf[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(p->stacktop()))
            {
                p->push(infix[i]);
                i++;
            }
            else
            {
                postf[j] = p->pop();
                j++;
            }
        }
    }
    while (!p->isEmpty())
    {
        postf[j] = p->pop();
        j++;
    }
    postf[j] = '\0';
    return postf;
}

int main()
{
    string infix = "a+b-c/d*e";
    string str = postfix(infix);
    cout << str;

    return 0;
}
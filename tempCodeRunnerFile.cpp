#include<iostream>
#include<iomanip>
using namespace std;
class insert {
    public:
int data;
insert *next;
};

void getDisplay(insert *head);
void insertAtIndex(insert *head, int index, int data);
int size(insert *head);
void deleteNode(insert *head, int n);
void reverse(insert *A);

int main()
{
    insert *A, *B, *C, *D;
    A = new insert;

    B = new insert;
    C = new insert;

    (*A).data = 3;
    A->next = B;

    B->data = 5;
    B->next = C;

    C->data = 11;
    C->next = NULL;

    insertAtIndex(A, 1, 34);
    insertAtIndex(A, 3, 54);
    getDisplay(A);
    deleteNode(A,3);
cout << endl;
    getDisplay(A);
    cout << endl;
    // reverse(A);
    // cout<<"NULL";
    
    // getDisplay(A);
    return 0;
}

void getDisplay(insert *head)
{

    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

void insertAtIndex(insert *head, int index, int data)
{
    insert *ptr = new insert;
    ptr->data = data;
    ptr->next = head;
    int i = 0;
    while (i < index-1)
    {
        head = head->next;
        i++;
    }
    ptr->next = head->next;
    head->next = ptr;
    head = ptr;
}

void reverse(insert *A)
{
    if(A!=NULL){
        reverse(A -> next);
           cout<<A-> data<<" -> ";   
           
    }
               
}

int size(insert *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void deleteNode(insert *head, int n)
{
    insert *p;
    p = head;

    int length = size(head);
    if(n >= length){
        cout<< "invalid index"<<endl;
    }
    else if(n == 0){
        head = head-> next;
        // delete p;
        // return;
    }
    else{
        int i = 0;
        while(i < n){
            p = p->next;
    }
    p-> next = p->next->next;
    // delete p->next;        
        }
}
#include <iostream>
using namespace std;
class insert
{
public:
    int data;
    insert *next;
};
insert *A = new insert;
void getDisplay(insert *head);
void insertAtIndex(insert *head, int index, int data);
void reverse();
int size(insert *head);
insert *deleteNode(insert *head, int n);
int mid(insert* head);
int find_data(insert* head, int element);

int main()
{
    insert *B, *C, *D;

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
    insertAtIndex(A, 3, 20);
    // insertAtIndex(A, 5, 19);

    getDisplay(A);
    cout << endl;
    // reverse();
    A = deleteNode(A,2);
    getDisplay(A);
    // cout<<mid(A);
    // cout<<find_data(A,11);
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
    while (i < index)
    {
        head = head->next;
        i++;
    }
    ptr->next = head->next;
    head->next = ptr;
    head = ptr;
}

void reverse()
{
    insert *prev = NULL;
    insert *current = A;
    insert *next;
    current = A;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    } 
    A = prev;
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

insert *deleteNode(insert *head, int n)
{
    insert *p;
    insert *q;
    p = head;
    q = head->next;
  
    int i = 0;
    while (i <= n - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p -> next = q->next;
    delete q;
    return head;
}

int mid(insert* head){
    insert *temp = head;
    
    for(int i = 1; i<size(A); i++ ){
        head = head -> next;
        temp = temp -> next -> next;
        if(temp == NULL || temp -> next == NULL){
            cout<<i<<endl;
            return head -> data;
        }
        
    }
    
}

int find_data(insert* head, int element){
    for(int i = 0; i< size(A); i++){
        
        if(head -> data == element){
            
            return i;
        }
        head = head -> next;
    }
}
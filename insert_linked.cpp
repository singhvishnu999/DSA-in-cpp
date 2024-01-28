#include <iostream>
#include <iomanip>
using namespace std;
class insert
{
public:
    int data;
    insert *next;
};
void getDisplay(insert *head)
{

    while (head != 0)
    {
        cout << head->data << " -> ";

        head = head->next;
    }
    cout << "NULL";
}

insert *insertAtfirst(insert *head, int data)
{
    insert *ptr = new insert;
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

void insertAtlast(insert *head, int data)
{
    insert *ptr = new insert;
    ptr->data = data;
    ptr->next = head;
    while (head->next = NULL)
    {
        head = head->next;
    }
    head->next = ptr;
    ptr->next = NULL;
    head = ptr;
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

void deletion(insert *head, int index)
{
    insert *curr = head;
    insert *next = head->next;
    int i = 0;
    if (head == NULL)
    {
    }
    while (i < index - 1)
    {
        curr = curr->next;
        next = next->next;
        i++;
    }
    curr->next = next->next;
    delete next;
}

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
    A = insertAtfirst(A, 15);
    A = insertAtfirst(A, 20);
    insertAtlast(C, 87);
    insertAtIndex(A, 2, 34);
    getDisplay(A);
    deletion(A, 4);
    cout <<endl<<"After Deletion"<< endl;
    getDisplay(A);

    return 0;
}
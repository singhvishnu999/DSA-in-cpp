#include <iostream>
using namespace std;

class linked{
    public:
    int data;
    linked *next;

};
void display(linked *head)
{
        linked *temp;
        temp = head;
        if(head!=NULL){
            do{
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            while(head != temp);
            }
        else{
            cout<<head->data;
        }
    }

void insertAtfirst(linked **head, int data)
{
    linked *t = new linked;
    linked* temp;
    temp = *head;
    t -> data = data;
if(*head == NULL){
    *head = t;
    t-> next = *head;
}
else{
    do{
        temp = temp -> next;
    }
while(temp->next != *head);

temp -> next = t;
    t -> next = *head;
}
*head = t;

}

void insertAtlast(linked **head, int data)
{
    linked *t = new linked;
    linked* temp;
    temp = *head;
    t -> data = data;
    do
    {
        temp = temp-> next;
    }
while(temp->next != *head);
temp -> next = t;
t -> next = *head;

}

int main()
{
    linked *head = new linked;
    linked *b = new linked;
    linked *c = new linked;
    linked *d = new linked;

    head -> data = 9;
    b->data = 7;
    c->data = 11;
    
    head->next = b;
    b->next = c;
    c->next = head;
    insertAtfirst(&head,65);
     insertAtlast(&head,5);

    display(head);
    return 0;
}
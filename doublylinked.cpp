#include<iostream>
using namespace std;
class linked{
   public:
   int data;
   linked *next;
   class linked *prev;

   void display(linked *head){
   while(head != NULL){
         cout<<head->data<<" -> ";
         head = head->next;
   }
   cout<<"NULL";
   }

linked* insertatbeg(linked *head,int ndata){
      linked *l1 = new linked;
      l1 ->data = ndata;
      l1-> next = head;
      l1-> prev = NULL;
      if(head != NULL){
         head -> prev = l1;
      }
      head = l1;
      return head;
   }

void insertatindex(linked *head,int data, int index)
{
   linked *temp = new linked;
   linked *l1;
   l1 = head;
   int i = 0;
   while(i<index){
      l1 = l1->next;
      i++;
   }
   temp -> data = data;
   temp -> next = l1 -> next;
   l1 -> next  = temp;
   temp -> prev = l1;
}

void insertatend(linked *head, int data){
   linked *temp = new linked;
   linked *l1 = head;
   while(l1->next!=NULL){
      l1 = l1-> next;
   }
   l1->next = temp;
   temp -> data = data;
   temp -> next = NULL;
   temp-> prev = l1;
}

void deletion(linked *head)
{
   
}

linked* reverse(linked *head)
{
   if(head == NULL){
      return head;
   }
   reverse(head->next);
   cout<<head->data<<" -> ";
}
   
};

int main(){
   class linked *l1 = new linked;
   class linked *l2 = new linked;
   linked *l3 = new linked;

   l1 -> data = 7;
   l2 -> data = 6;
   l3 -> data = 9;

   l1 -> next = l2;
   l2 -> next = l3;
   l3 -> next = NULL;

   l1-> prev = NULL;
   l2 -> prev = l1;
   l3 -> prev = l2;

   l1=l1->insertatbeg(l1,12);
   l1-> insertatindex(l1,15,2);
   l1-> insertatend(l1,20);
   l1->reverse(l1);
   cout<<"NULL"<<endl;
   l1-> display(l1);
   
return 0;
}
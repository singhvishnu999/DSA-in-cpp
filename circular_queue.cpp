#include<iostream>
using namespace std;
class Queue{
    public:
    int f;
    int r;
    int size;
    int *arr;
    
};
void display(Queue &q){
    if(q.f == -1){
        cout<<"Queue is empty.";
    }
   if(q.r>q.f){
    for(int i = q.f; i <= q.r; i++){
        cout<<q.arr[i]<<" "<<i<<endl;
    }
   }
    else{
         for(int i=0; i<=q.r; i++){
            cout<<q.arr[i]<<" "<<i<<endl;
        }
        for(int i = q.f; i<q.size; i++){
            cout<<q.arr[i]<<" "<<i<<endl;
        }
       
    }

}

void insert(Queue &q, int data){
    if((q.r+1)%q.size == q.f){
        cout<<"Queue is full"<<endl;
    }

    else 
    {
        if(q.r == -1 && q.f == -1){
            q.r = 0; 
            q.f = 0;
            
    }
        else{
            q.r = (q.r+1) % (q.size);  
           
            }
            q.arr[q.r] = data;
            // cout<<q.arr[q.r]<<" ";
        }
    }

int dequeue(Queue &q){
    int data;
    if(q.f == -1 && q.r == -1)
    {
        cout<<"Queue is underflow, cannot pop "<<endl;
        return -1;
    }
    else{
        data = q.arr[q.f];
        q.f = (q.f+1) % q.size;
    }
    return data;
}

int main(){
    Queue q1;
    q1.f = -1;
    q1.r = -1;
    q1.size = 5;
    q1.arr = new int[q1.size];
    insert(q1,20);
    insert(q1,45);
    insert(q1,23);
    insert(q1,33);
    insert(q1,32);
    display(q1);
     cout<<endl<<"After dequeue "<<endl;
    cout<<dequeue(q1)<<" "; 
    cout<<dequeue(q1); 
    cout<<endl;

    insert(q1,32);
    // insert(q1,12);
    // insert(q1,87);
    display(q1);
    delete q1.arr;
}
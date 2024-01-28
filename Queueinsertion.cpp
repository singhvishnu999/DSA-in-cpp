
//************IMPLEMENTATION OF LINEAR QUEUE USING ARRAY***********************

#include <iostream>
#define size 10
using namespace std;
class Queue{
    int front;
    int rear;
    int *arr;
public:
    Queue(){
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int data)
    {
        if (rear == size - 1)
        {
            cout << "Queue is Overflow,Element is not inserted." << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
        
    }

    int pop(){
        int val;
        if (front == rear+1 || front ==-1)
        {
            cout << "Queue is underflow" << endl;
            return -1;
        }
        else
        {
            val = arr[front];
            front++;
        }
        return val;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty."<<endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
    }
};

int main(){
    Queue q1, q2;
    q1.push(1);
    q1.push(3);
    q1.push(9);
    q1.push(8);
    q1.push(34);
    // q1.push(42);
    // q1.push(72);
    // q1.push(22);
    // q1.push(12);
    // q1.push(92);
    // q1.push(82);  Element is not inserted bcz queue is ovrflow
    // q1.push(32);
     q1.display();
     cout<<"After deletion element in queue are: "<<endl;
    q1.pop();
    q1.pop();
    q1.display();
}

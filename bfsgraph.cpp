#include <iostream>
using namespace std;
class Queue{
    int front;
    int rear;
    int *arr;
    int size = 100;
public:
    Queue(){
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void enqueue(int data)
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

    int dequeue(){
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
    int isEmpty(){
        if(front == -1 || front == rear+1){
            return 1;
        }
        return 0;
    }
};

 int visited[10] = {0,0,0,0,0,0,0,0,0,0};
    int graph[10][10] ={
         {0,1,1,0,0,1,0,0,0,1}, {1,0,0,0,1,0,1,0,0,0}, {0,0,1,0,1,0,1,0,0,0}, {1,0,0,0,1,0,0,0,0,0}, {0,0,0,0,0,0,0,0,1,0}, 
        {0,1,0,0,0,0,0,1,0,0}, {0,1,0,0,0,0,0,1,0,0}, {0,0,1,1,0,1,0,0,0,1}, {0,0,0,0,1,0,1,0,0,0}, {0,0,0,0,0,1,0,0,1,1},
    };

int DFS(int i){
    cout<<i<<" ";
    visited[i] = 1;
    for(int j = 0; j < 10; j++){
        if(graph[i][j] == 1 && visited[j] == 0){
            DFS(j);
        }
    }
}

int main(){
    Queue q;
//    DFS(0);

    int i = 0;
    visited[i] = 1;
    cout<<i<<" ";
    q.enqueue(i);
    while(!q.isEmpty()){
        int node = q.dequeue();
        for(int j = 0; j < 10; j++){
           if(graph[node][j] == 1 && visited[j] == 0){
            cout<<j<<" ";
            visited[j] = 1;
            q.enqueue(j);
           }
        }

    }
}
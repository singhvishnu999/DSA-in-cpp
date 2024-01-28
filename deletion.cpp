#include<iostream>
using namespace std;
void display(int arr[], int n){
    for ( int i= 0; i<n; i++){
        cout<<arr[i];
    }
    cout<<endl;
}

int del(int arr[], int size, int index, int capacity){
    if(size >= capacity){
        return -1;
    }
    for(int i = index; i<=size; i++){
        arr[i]=arr[i+1];
    }

}

int main(){
    int arr[10] = {1,5,8,6,7,5};
    display(arr,6);
    del(arr,5,5,10);
    display(arr,5);
        return 0;
}
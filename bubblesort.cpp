#include<iostream> 
using namespace std;

void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int arr[], int n){
    for(int i= 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
void bubble(int arr[], int n)
{
    int isSorted = 0;
    for(int i = 0; i<n-1; i++){
        // cout<<i+1;
        isSorted = 1;
        for(int j= 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                isSorted = 0;
            }
        }
        if(isSorted){
            return;
        }
    }
    }

int main(){
    int arr[] = {11,32,25,41,85,67,47,61};
    int size = sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    bubble(arr,size);
    cout<<endl<<"after sorting array is "<<endl;
    display(arr,size);
    return 0;
}
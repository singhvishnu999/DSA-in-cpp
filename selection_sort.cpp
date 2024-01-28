#include <iostream>
using namespace std;
void display(int arr[] , int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void swap(int *a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        int min = i;
       for(int j = i+1; j < n; j++)
        {
            if(A[j] < A[min])
            {
                min = j;
            }
        }
        swap(&A[i], &A[min]);
    }
}

int main()
{
    int arr[] = {23, 54, 34, 98, 4, 55, 12, 87};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    selection(arr, size);
    cout<<endl;
    display(arr, size);
}
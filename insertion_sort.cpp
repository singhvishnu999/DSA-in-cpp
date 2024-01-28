#include <iostream>
using namespace std;

void display(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
void insertion_sort(int arr[], int n)
{
    int j;
    int key;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int size;
    cout<<"Enter Size of array";
    cin >> size;
    int arr[size];
    cout << "Enter Unsorted array :";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    display(arr, size);
    insertion_sort(arr, size);
    display(arr, size);
    return 0;
}

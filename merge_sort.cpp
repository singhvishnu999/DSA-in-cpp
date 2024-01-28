#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int B[100];
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            B[k] = arr[j];     
            j++;
        }
        else
        {
            B[k] = arr[i];
            i++;
        }
        k++;
    }
    while (i <= mid)
    {
        B[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i <= high; i++)
    {
        arr[i] = B[i];
    }
}

void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {23, 54, 34, 98, 4, 55, 12, 87, 54};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    mergesort(arr, 0, size - 1);
    cout << endl;
    display(arr, size);
}
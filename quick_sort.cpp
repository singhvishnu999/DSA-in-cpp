#include <iostream>
using namespace std;
void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int j = high;
    int i = low + 1;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);
    swap(&arr[j], &arr[low]);
    return j;
}

void quick(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quick(arr, low, p - 1);
        quick(arr, p + 1, high);
    }
}

int main()
{
    int arr[] = {23, 54, 67, 55, 34, 22, 9, 17, 54};
    int size = sizeof(arr) / sizeof(arr[1]);
    // cout<<partition(arr,0,n-1);
    print_arr(arr, size);
    cout << endl
         << "After sorting array is " << endl;
    quick(arr, 0, size - 1);
    print_arr(arr, size);
    return 0;
}
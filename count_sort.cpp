#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int maxi(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void count_sort(int arr[], int size)
{
    int max = maxi(arr, size) + 1;
    int *aux = new int[max];
    int i, j;
    for (i = 0; i < max; i++)
    {
        aux[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        aux[arr[i]]++;
    }

    i = j = 0;
    while (i < max)
    {
        if (aux[i] != 0)
        {
            arr[j] = i;
            aux[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
    delete (aux);
}

int main()
{
    int arr[] = {1, 3, 5, 3, 2, 8, 6, 9, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    count_sort(arr, size);
    cout << endl;
    display(arr, size);
    return 0;
}
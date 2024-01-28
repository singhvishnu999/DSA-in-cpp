#include <iostream>
#include <iomanip>
using namespace std;
int arr[3][3];
const int row = 3;
const int column = 3;

void insertion(int arr[row][column]);
void traversal();
void deletion();
int sum();

void traversal()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void insertion(int arr[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << "enter elements at index " << i << j << ": ";
            cin >> arr[i][j];
        }
    }
}

void deletion()
{
    int n;
    int c;
    cout << "choose 0 for row and 1 for column whicn have to delete " << endl;
    cin >> c;
    cout << "enter rows/column which have to delete : ";
    cin >> n;
    if (c == 0)
    {
        for (int i = 0; i < row; i++)
        {
            if (i == n) { continue;}
            for (int j = 0; j < column; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    else if (c == 1)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (j == n){continue;}
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "invalid input" << endl;
    }
}

int sum()
{
    int add = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            add = add + arr[i][j];
        }
    }
    return add;
}

int main()
{
    int arrt[3][3];
    insertion(arr);
    traversal();
    cout << endl;
    deletion();
    cout << "the sum of all element of array is : " << sum();
    return 0;
}
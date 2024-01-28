#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cout << "enter number of elements ";
	cin >> n;
	int arr[n];
	cout << "enter element of array"<<endl;
	for (int i = 0; i <= n; i++)
	{
		cin >> arr[i];
	}

	cout << endl;
	int temp = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (arr[i] >= arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	int a = 16;
	int count=0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == a)
		{
			cout <<arr[i]<<" is present at "<< i << endl;
			count++;
		}
	}
	cout << count << endl;

	return 0;
}
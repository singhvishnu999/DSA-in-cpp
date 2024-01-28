#include <iostream>
using namespace std;
int binarySearch(int arr[], int element, int beg, int end){
    
    while(beg <= end){
    int mid = (beg + end) / 2;
    if (arr[mid]==element){
        return mid;
    }
    else if(arr[mid] >= element){
        end = mid-1;
    }
    else {
        beg = mid+1;
    }
    
    }
    return -1;
}

int main(){
    int arr[] = {2,4,5,6,9,11,14,17,19,23,26,29,31};
    int n = sizeof(arr)/sizeof(int);
    int element;
    cout<<"enter element which has to search: ";
    cin>>element;
    int low = 0;
    int high = n-1;

    int result = binarySearch(arr, element, low, high);
    cout<<"element is present at index "<<result;
    return 0;
    }
#include<iostream>
using namespace std;
void get_array(int arr[], int n){
for(int i = 0; i<n; i++){
    cout<<arr[i];
}
}
int insert(int arr[], int element, int size, int capacity, int index){
        if(size >= capacity){
            return -1;
        }

             for(int i = size ; i >= index; i--){
        arr[i+1] = arr[i];
             }
    arr[index] = element;

return 1;
}

int main(){
    
int arr[10] = {1,2,3,4,5,6};
get_array(arr,6);
cout<<endl;
insert(arr,58,5,10,2);
get_array(arr,7);
return 0;

}
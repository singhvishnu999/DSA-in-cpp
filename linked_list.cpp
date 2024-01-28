#include <iostream>
using namespace std;
class linked{
    public:
    int data;
    int data2;
    class linked *ptr; 
    
};
void getdata(linked *l1){
    while(l1!=NULL){
        cout<<"the value of data is "<<l1->data<<endl;
        cout<<"the value of data2 is "<<l1->data2<<endl;
        l1 = l1->ptr;
    }
}

void set_data(linked *l1){
    cout<<"enter data of node : "<<endl;
    cin>>(*l1).data;
    cin>>l1->data2;
    
}

// int * ptr = (int*)malloc(10*sizeof(int))
int main(){
    linked *first, *second, *third;
    
    first = new linked;
    second = new linked;
    third = new linked;

    // linked 1st and 2nd element
    (*first).data=7;
    first->data2 = 23;
    first->ptr=second;
    // set_data(first);

    // linked 2nd and 3rd object;
    second->data = 11;
    (*second).data2 = 26;
    second->ptr = third;

    // linked 3rd and 4th node;
    third->data = 17;
    third-> data2 = 97;
    third->ptr = NULL;

    // getdata(first);

    cout<<"the value of data is "<<first->data<<endl;
  return 0;
}
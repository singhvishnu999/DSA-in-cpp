#include <iostream>
#include <iomanip>
using namespace std;
void tower( int num, char a, char b, char c){
    if (num == 1){
        cout<<"disc 1 move from "<<a<<" to "<<b<<endl;
        return ;
    }
    tower(num-1, a,c,b);
    cout<<"disc "<<num<<" move from tower "<<a<<" to "<<b<<endl;
    tower(num-1, c,b,a);
}

int main(){
    int num;
cout<<"enter number of disc : "<<endl;
cin>>num;
tower(num,'A','B','C');
    return 0;
}
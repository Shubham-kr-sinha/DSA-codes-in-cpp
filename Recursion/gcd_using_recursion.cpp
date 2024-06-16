#include<iostream>
using namespace std;

int gcd(int divis,int divid){
    if(divid%divis == 0) return divis;
    return gcd((divid % divis),divis);
}

int main(){
    int a,b;
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}
#include<iostream>
#include<string>
using namespace std;

void generatebin(string s, int n){
    if(n==0){
        cout<<s<<endl;
        return;
    }
    generatebin(s+'0',n-1);
    if (s.size()==0 || s[s.size()-1] == '0') generatebin(s+'1',n-1);
}

int main(){
    int n;
    cin>>n;
    generatebin("",n);
}
#include<iostream>
#include<string>
using namespace std;

void subset(string ans, string str){
    if (str == ""){
        cout<<ans<<endl;
        return;
    }
    char ch = str[0];
    subset(ans + ch, str.substr(1));
    subset(ans, str.substr(1));
}

int main(){
    string str = "abc";
    subset("",str);
}
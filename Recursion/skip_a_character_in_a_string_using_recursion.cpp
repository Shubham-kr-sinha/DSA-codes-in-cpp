#include<iostream>
#include<string>
using namespace std;

void removechar(string ans, string str){
    if (str.length() == 0){
        cout << ans; 
        return;
    }
    char ch = str[0];
    if (ch == 'a') removechar(ans, str.substr(1));
    else removechar(ans + ch, str.substr(1));
}


int main(){
    string str = "physics wallah";
    removechar("",str);
}
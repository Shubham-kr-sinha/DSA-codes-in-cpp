#include<iostream>
#include<stack>
#include<string>
using namespace std;

string solve(string val1, string val2, char ch){
    string s = "";
    s += val1;
    s += val2;
    s.push_back(ch);
    return s;
}

int main(){
    string s = "-/*+79483";
    stack<string> st;
    for(int i=s.size()-1;i>=0;i--){
        if (s[i] >=48 && s[i] <=57) st.push(to_string(s[i]-48));
        else{
            string val1 = st.top();
            st.pop();
            string val2 = st.top();
            st.pop();
            string ans = solve(val1, val2, s[i]);
            st.push(ans);
        }
    }
    cout<< st.top() << endl;
    
}
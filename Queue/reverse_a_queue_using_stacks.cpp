#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int>& q){
    stack<int> st;
    while(q.size()>0){
        int x = q.front();
        q.pop();
        st.push(x);
    }
    while(st.size()>0){
        int x = st.top();
        cout<<x<<endl;
        st.pop();
        q.push(x);
    }
}


void display(queue<int>& q){
    int n = q.size();
    for(int i=0;i<q.size();i++){
        int x = q.front();
        cout<< x <<endl;
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    display(q);
    reverse(q);
    
}
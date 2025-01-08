#include<iostream>
#include<stack>
using namespace std;

class Queue{
public:
    stack<int> st;
    stack<int> helper;
    Queue(){

    }
    void push(int x){
        st.push(x);
    }
    void pop(){
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        helper.pop();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
    }

    int front(){
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    void display(){
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        while(helper.size()>0){
            cout<<helper.top()<<" ";
            st.push(helper.top());
            helper.pop();
        }
        cout<<endl;
    }
    bool empty(){
        if(st.size() == 0) return true;
        else return false;
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    q.pop();
    q.front();
    q.display();

}
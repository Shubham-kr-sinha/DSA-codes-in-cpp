#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Deque{
public:
    Node* head;
    Node* tail;
    int s;
    Deque(){
        head = tail = NULL;
        s = 0;
    }
    void push_back(int val){
        Node* temp = new Node(val);
        if(s==0) head = tail = temp;
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        s++;
    }
    void push_front(int val){
        Node* temp = new Node(val);
        if(s==0) head = tail = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        s++;
    }
    void pop_front(){
        if(s==0){
            cout<<"List is Empty!";
            return;
        }
        head = head->next;
        if(head) head->prev = NULL;
        if(head == NULL) tail = NULL;
        s--;
    }
    void pop_back(){
        if(s==0){
            cout<<"List is Empty!";
            return;
        }
        else if(s==1){
            pop_front();
            return;
        }
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        s--;
    }
    int front(){
        if(s==0){
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }
        return head->val;
    }
    int back(){
        if(s==0){
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }
        return tail->val;
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s == 0) return true;
        else return false;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Deque dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.display();
    dq.pop_back();
    dq.display();
    dq.pop_front();
    dq.display();
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
}

#include<iostream>
using namespace std;

class Student{
    public:
    string name;
    int rno;
    float marks;
    Student(string name, int rno, float marks){
        this->name = name;
        this->rno = rno;
        this->marks = marks;
    }
};

void change(Student* s){
    s->name = "Siddhant";
}

int main(){
    Student s("Shubham", 1236, 8.89);
    cout<<s.name<<endl;
    change(&s);
    cout<<s.name<<endl;
}
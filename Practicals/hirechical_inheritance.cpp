#include<iostream>
using namespace std;

class A
{
public:
    int a,b;
    void get(){
        cout<<"Enter two numbers: ";
        cin>>a>>b;
    }
};

class B:public A{
public:
    void sum(){
        cout << "Sum of two numbers: " << a + b << endl;
    }
};

class C:public A{
public:
    void sub(){
        cout<<"Subtraction of two numbers: "<<a-b<<endl;
    }
};

int main() {
    C obj1;  
    obj1.get();
    obj1.sub();

    B obj2; 
    obj2.get(); 
    obj2.sum(); 

    return 0;
}


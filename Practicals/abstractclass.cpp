#include<iostream>
using namespace std;
class Base
{
    public:
        // virtual void add()=0;
        // virtual void show()=0;
        void display()
        {
            cout<<"Display"<<endl;
        }
};

class Derived:public Base
{
    public:
        void show()
        {
            cout<<"Hello"<<endl;
        }
        void add()
        {
            int a=10,b=10;
            cout<<"Addition="<<a+b<<endl;
        }
};

class Derived2:public Base
{
    public:
        void show()
        {
            cout<<"Hello From derived 2."<<endl;
        }
        void add()
        {
            int a=100,b=200;
            cout<<"Addition="<<a+b<<endl;
        }
};

int main()
{
    Derived d1;
    d1.add();
    d1.show();

    Derived2 d2;
    d2.add();
    d2.show();
    
    return 0;
}
#include <iostream>
using namespace std;
class A
{
    public:
        int x=100;
        virtual void show()
        {
            cout<<"Value of X:"<<x<<endl;
        }
};

class D:public A
{
    public:
        int y=300;
        virtual void show()
        {
            cout<<"Value of y:"<<y<<endl;
            cout<<"Value of X:"<<x<<endl;
        }
};

int main()
{
    // A a1;
    // D d1;
    // a1=d1;
    // a1.show();
    A *a1;
    D d1;
    a1=&d1;
    return 0;
}
#include <iostream>
using namespace std;
class Count
{
    int num;
    public:
        Count(int n=0):num(n){}
        Count operator ++()
        {
            return num++;
        }

        void display()
        {
            cout<<num;
        }
};

int main()
{
    Count c1(10);
    Count c2=++c1;
    c2.display();
    return 0;
}
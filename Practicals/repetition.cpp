#include <iostream>
using namespace std;

class repeat
{
    string str;
    int count;
    public:
        repeat(string msg,int cnt):str(msg),count(cnt){}
        repeat operator *()
        {
            for(int i=0;i<count;i++)
            {
                cout<<str;
                i<count?cout<<",":cout<<".";
            }
        }
};

int main()
{
    repeat r1("Hello",5);
    repeat r2=*r1;
    return 0;
}
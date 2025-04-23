#include <iostream>
using namespace std;
// creating template for function of any for any datatype
template <typename any>
any findMax(any num1,any num2)
{
    return num1>num2?num1:num2;
}

// creating template for class calculator
template <typename T>
class Calculator
{
    private:
        T num1,num2;
    public:
        // constructor for initializing values
        Calculator(T n1,T n2):num1(n1),num2(n2){}
        // mathematical operations 
        T add()
        {
            return num1+num2;
        }

        T sub()
        {
            return num1-num2;
        }

        T mul()
        {
            return num1*num2;
        }

        T div()
        {
            return num1/num2;
        }
}; 

// main function
int main()
{
    int n1,n2;
    float f1,f2;
    double d1,d2;
    // accepting values from user
    cout<<"Enter 1st Integer:";
    cin>>n1;
    cout<<"Enter 2nd Integer:";
    cin>>n2;
    cout<<"Enter 1st Float Integer:";
    cin>>f1;
    cout<<"Enter 2nd Float Integer:";
    cin>>f2;
    cout<<"Enter 1st Double Integer:";
    cin>>d1;
    cout<<"Enter 2nd Double Integer:";
    cin>>d2;

    // finding maximum value
    cout<<"Max of "<<n1<<" and "<<n2<<" is "<<findMax(n1,n2)<<endl;
    cout<<"Max of "<<f1<<" and "<<f2<<" is "<<findMax(f1,f2)<<endl;
    cout<<"Max of "<<d1<<" and "<<d2<<" is "<<findMax(d1,d2)<<endl;

    // for integer calculation
    Calculator <int> calculate_int(n1,n2);
    cout<<"Integer Operations:";
    cout<<n1<<" + "<<n2<<" = "<<calculate_int.add()<<", ";
    cout<<n1<<" - "<<n2<<" = "<<calculate_int.sub()<<", ";
    cout<<n1<<" * "<<n2<<" = "<<calculate_int.mul()<<", ";
    cout<<n1<<" / "<<n2<<" = "<<calculate_int.div()<<endl;

    // for float calculation 
    Calculator <float> calculate_float(f1,f2);
    cout<<"Float Operations:";
    cout<<f1<<" + "<<f2<<" = "<<calculate_float.add()<<", ";
    cout<<f1<<" - "<<f2<<" = "<<calculate_float.sub()<<", ";
    cout<<f1<<" * "<<f2<<" = "<<calculate_float.mul()<<", ";
    cout<<f1<<" / "<<f2<<" = "<<calculate_float.div()<<endl;

    // for double calculation
    Calculator <double> calculate_double(d1,d2);
    cout<<"Double Operations:";
    cout<<d1<<" + "<<d2<<" = "<<calculate_double.add()<<", ";
    cout<<d1<<" - "<<d2<<" = "<<calculate_double.sub()<<", ";
    cout<<d1<<" * "<<d2<<" = "<<calculate_double.mul()<<", ";
    cout<<d1<<" / "<<d2<<" = "<<calculate_double.div()<<endl;

    return 0;
}
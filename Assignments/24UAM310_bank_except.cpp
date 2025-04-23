#include <iostream>
//exception class for custom exceptions. 
#include <exception>

using namespace std;
//Custom exception classes. 
class InsufficientFundsException : public exception
{
    const char* what() const noexcept override
    {
        return "Insufficient Funds.";
    }
};

class InvalidTransactionException : public exception
{
    const char* what() const noexcept override
    {
        return "Invalid Transaction.";
    }
};

class DivideByZeroException : public exception
{
    const char* what() const noexcept override
    {
        return "can't divide by zero.";
    }
};

//bank class
class BankAccount
{
private:
    string ownerName;
    double balance;
public:
    BankAccount(string owe, double init_deposit)
    {
        if(init_deposit < 0)
        {
            throw InvalidTransactionException();
        }
        ownerName=owe;
        balance=init_deposit;

        cout << "Owner Name:" << ownerName <<",Balance:"<< balance <<" Rs."<< endl;
    }

    void deposit(double amount)
    {
        if(amount < 0)
        {
            throw InvalidTransactionException();
        }
        balance+=amount;
        cout << "Depositing " <<amount <<" Rs into " << ownerName << " Account."<< endl;
    }

    void withdraw(double amount)
    {
        if(amount < 0)
        {
            throw InvalidTransactionException();
        }

        if(amount > balance)
        {
            throw InsufficientFundsException();
        }
        balance-=amount;
        
        cout << "Withdrawing " << amount <<" Rs from " << ownerName << " Account."<< endl;
    }

    void transfer(BankAccount &b,double amount)
    {
        if(amount < 0)
        {
            throw InvalidTransactionException();
        }
        withdraw(amount);
        b.deposit(amount);

        cout << "Transferring " << amount << " Rs from " << ownerName << " to "<< b.ownerName<<endl;
    }

    void divideBalance(double value)
    {
        if(value==0)
        {
            throw DivideByZeroException();
        }
        balance/=value;
        cout<<"Balance after division="<< balance << endl;
    }

    void display()
    {
        cout << "Owner Name:" << ownerName <<",Balance:"<< balance <<" Rs."<< endl;
    }
};

//main function
int main()
{
    BankAccount rahul("Rahul Sharma",5000);
    try
    {
        rahul.deposit(-78);
    }
    catch(const exception &e)
    {
        cout<<e.what()<<endl;
    }
    try
    {
        rahul.withdraw(89000);
    }
    catch(const exception &e)
    {
        cout<<e.what()<<endl;
    }

    BankAccount abc("ABC",3000);
    try
    {
        rahul.transfer(abc,4000);
    }
    catch(const exception &e)
    {
        cout << e.what() << endl;
    }

    rahul.display();
    abc. display();

    try
    {
        rahul.divideBalance(0);
    }
    catch(const exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}

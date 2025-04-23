// 24UAM310:function overloading and operator overloading in banking system
#include <iostream>
using namespace std;
// creating bank class
class Bank
{
    public:
        void deposit(int amount)
        {
            cout<<"Depositing "<<amount<<"RS in cash."<<endl;
        }

        void deposit(float amount)
        {
            cout<<"Depositing "<<amount<<"Rs via digital payment."<<endl;
        }

        void deposit(string upiID)
        {
            int amount;
            cout<<"Enter amount pay via UPI:";
            cin>>amount;
            cout<<"Depositing "<<amount<<"Rs using UPI ("<<upiID<<")."<<endl;
        }
};

// creating account class
class Account
{
    private:  
        int accountNumber;
        double balance;
    
    public:
        Account(int acc_no,double acc_bal):accountNumber(acc_no),balance(acc_bal){}
        void display()
        {
            cout<<"Account:"<<accountNumber<<"\tBalance:"<<balance<<"Rs"<<endl;
        }

        // for transfer fund
        Account operator + (double amount)
        {
            balance+=amount;
            return *this;
        }

        // for withdraw fund
        Account operator - (double amount)
        {
            if(balance>=amount)
            {
                balance-=amount;
            }
            else 
            {
                cout<<"Insufficent Amount.";
            }
            return *this;
        }

        void transfer(Account &obj,double amount)
        {
            if(balance>=amount)
            {
                balance-=amount;
                obj.balance+=amount;
                cout<<"Transferring "<<amount<<" from Account "<<accountNumber<<" to account "<<obj.accountNumber<<"..."<<endl;
            }
            else
            {
                cout<<"Transfer Failed:Insufficient balance."<<endl;
            }
        }
};

int main()
{
    cout<<"............................................................."<<endl;
    // creating bank object
    Bank b;
    b.deposit(7000);
    b.deposit(1000.10f);
    b.deposit("Phonepe23746@UPI");

    // creating accounts
    Account acc1(23746,10000);
    Account acc2(83972,5000);
    acc1.display();
    acc2.display();

    cout<<"............................................................."<<endl;

    // transferring amount 
    acc1.transfer(acc2,3000);
    acc1.display();
    acc2.display();

    cout<<"............................................................."<<endl;

    // withdrawing amount
    acc1=acc1-2000;
    cout<<"Withdrawing "<<2000<<" from account 1..."<<endl;
    acc1.display();

    return 0;
}

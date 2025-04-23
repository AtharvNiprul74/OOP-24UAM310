// Bank Account System using oop.
#include <iostream>
using namespace std;

//Creating bankAccount class.
class BankAccount
{
    //Defining class attributes.
    private:
        string accountHolder;
        int accountNumber;
        string accountType;
        double balance;

    public:
    //Creating default constructor.
    BankAccount()
    {
        accountHolder="User";
        accountNumber=00000;
        accountType="Savings";
        balance=0;
    }

    //Creating paramerized constructor.
    BankAccount(string holder_name,int acc_no,string acc_type,double acc_balance)
    {
        accountHolder=holder_name;
        accountNumber=acc_no;
        accountType=acc_type;
        balance=acc_balance;
    }

    //implemanting accessor functions.
    string getAccountHolder()
    {
        return accountHolder;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    string getAccountType()
    {
        return accountType;
    }

    double getBalance()
    {
        return balance;
    }

    // implementing mutator function.
    void setAccountType(string account_type)
    {
        accountType=account_type;
        cout<<"Updated account type to "<<accountType<<"."<<endl;
    }

    // implementing functional methodes to deposit and withdraw amount.
    void deposit(double amount)
    {
        if(amount>0)
        {
            cout<<"Depositing "<<amount<<" Rs."<<endl;
            balance=balance+amount;
            cout<<"New Balance:"<<balance<<" Rs."<<endl<<"\n";
        }
    }

    void withdraw(double amount)
    {
        if(amount>balance)
        {
            cout<<"Insufficient Balance.";
            return;
        }
        cout<<"Withdrawing "<<amount<<" Rs."<<endl;
        balance=balance-amount;
        cout<<"New Balance:"<<balance<<" Rs."<<endl<<"\n";
    }

    // Displaying account details.
    void displayAccountDetails()
    {
        cout<<"Account Details:"<<endl;
        cout<<"Holder:"<<accountHolder<<endl;
        cout<<"Account Number:"<<accountNumber<<endl;
        cout<<"Type:"<<accountType<<endl;
        cout<<"Balance:"<<balance<<" Rs."<<endl;
    }
};

// creating main function.
int main()
{
    int deposit_amt,withdraw_amt;
    // Creating class object using default constructor. 
    BankAccount b1;
    b1.displayAccountDetails();
    cout<<"\n";

    // Creating class object using parameterized constructor.
    BankAccount b2("Atharv Niprul",123456,"Savings",30000);
    b2.displayAccountDetails();
    cout<<"\n";

    // Depositing and withdrawing money.
    cout<<"Enter Amount to deposit:";
    cin>>deposit_amt;
    b2.deposit(deposit_amt);

    cout<<"Enter Amount to Withdraw:";
    cin>>withdraw_amt;
    b2.withdraw(withdraw_amt);

    // Using accessor method.
    cout<<"Holder:"<<b2.getAccountHolder()<<endl;
    cout<<"Account Number:"<<b2.getAccountNumber()<<endl;
    cout<<"Type:"<<b2.getAccountType()<<endl;
    cout<<"Balance:"<<b2.getBalance()<<" Rs."<<endl;
    cout<<"\n";

    // Implementation of mutator method.
    string type;
    cout<<"Enter Account Type:";
    cin>>type;
    b2.setAccountType(type);
    cout<<"\n";
    b2.displayAccountDetails();
    cout<<"\n";

    // Creating object with user defined values
    string holder_Name,acc_Type;
    int acc_Number;
    double acc_Balance;

    cout<<"Enter Account Holder Name:";
    cin>>holder_Name;
    cout<<"Enter Account Number:";
    cin>>acc_Number;
    cout<<"Enter Account Type:";
    cin>>acc_Type;
    cout<<"Enter Account Balance:";
    cin>>acc_Balance;
    cout<<"\n";

    // creating new object with user inputs.
    BankAccount b3(holder_Name,acc_Number,acc_Type,acc_Balance);
    b3.displayAccountDetails();
    return 0;
}

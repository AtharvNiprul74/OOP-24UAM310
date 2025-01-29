#include<iostream>
#include<fstream>
#include <vector>
using namespace std;
int dep_amt(int *b)
{
    int amount;
    cout<<"Enter amount to deposite:";
    cin>>amount;
    *b+=amount;
    string st="+"+to_string(amount)+" Rs";
    ofstream file("records.txt",ios::app);
    file<<st<<endl;
    file.close();
    cout<<amount<<"rs "<<"deposited successfully.\n"<<endl;
    return 1;
}
int withdraw_amt(int *b,int amount)
{
    if(amount<*b)
    {
        *b-=amount;
        string st="-"+to_string(amount)+" Rs";
        ofstream file("records.txt",ios::app);
        file<<st<<endl;
        file.close();
        return 1;
    }
    return 0;
}


void readfromfile()
{
    string lines[10];
    int count = 0;
    string line;
    ifstream file("records.txt");
    while (getline(file, line)) {
        lines[count % 10] = line;
        count++;
    }
    int start = count > 10 ? count % 10 : 0;
    int total = count > 10 ? 10 : count;
    for (int i = 0; i < total; i++) {
        cout << lines[(start + i) % 10] << endl;
    }
}
int main()
{
    int balance = 0;
    int ch;
    ofstream file("records.txt",ios::trunc);
    file.close();
    cout << "-----------------------------------------" << endl;
    cout << "         Welcome to OOP Bank             " << endl;
    cout << "-----------------------------------------" << endl;
    do 
    {
        cout<<"1.Deposite Amount"<<endl;
        cout<<"2.Withdraw Amount"<<endl;
        cout<<"3.Last 10 Transactions"<<endl;
        cout<<"4.exit"<<endl;
        cout<<"Enter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
            dep_amt(&balance);
            break;

            case 2:
                int amount;
                cout<<"Enter amount to withdraw:";
                cin>>amount;
                if(withdraw_amt(&balance,amount))
                {
                    cout<<amount<<"rs "<<"withdraw successfully."<<endl;
                }
                else
                {
                    cout<<"Insufficient balance.\n"<<endl;
                }
            break;

            case 3:
                readfromfile();
            break;

            case 4:
                cout<<"Exiting....";
                exit(0);
        }
    }while(1);
    return 0; 
}
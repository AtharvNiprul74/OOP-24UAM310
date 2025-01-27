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
int readfromfile()
{
    ifstream file("records.txt");
    vector<string> records;
    string line;
    while (getline(file, line)) 
    {
        records.push_back(line);
    }
    file.close();

    int count = records.size();
    cout << "\nLast 10 Transactions:\n";
    for (int i = max(0, count - 10); i < count; ++i) 
    {
        cout << records[i] << endl;
    }
    return 0;
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
                if(dep_amt(&balance))
                {
                    cout<<balance<<"rs "<<"deposited successfully.\n"<<endl;
                }
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
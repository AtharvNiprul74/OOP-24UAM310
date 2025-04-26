#include <iostream>
#include <string>
// including STL libraries
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// main code
int main()
{
    // map for storing student data.
    map<string,vector<int>> stud_marks;
    int no_of_students;
    cout<<"Enter Number of Students:";
    cin>>no_of_students;

    for(int i=0;i<no_of_students;++i)
    {
        string stud_name;
        vector<int> marks(3);
        cout<<"Enter Student Name:";
        cin>>stud_name;
        for(int j=0;j<3;++j)
        {
            cout<<"Enter Marks for "<<j+1<<" subject:";
            cin>>marks[j];
        }
        // storing marks at student name.
        stud_marks[stud_name]=marks;
    }
    cout<<"Student Details:\n";
    // to store averages.
    vector<pair<string,double>> stud_averages;
    // map<string,vector<int>>::iterator it = stud_marks.begin(); 
    for(auto it=stud_marks.begin();it!=stud_marks.end();++it)
    {
        string name=it->first;
        vector<int> marks=it->second;

        int total=accumulate(marks.begin(),marks.end(),0);
        double average=static_cast<double>(total)/marks.size();

        cout<<"Student:"<<name<<", Marks:";
        for(int mark:marks)
        {
            cout<<mark<<" ";
        }
        cout<<", Average:"<<average<<endl;
        stud_averages.push_back({name,average});
    }
    // finding student by using max_element.
    auto topper=max_element(stud_averages.begin(),stud_averages.end(),[](const pair<string,double>&a , const pair<string,double>&b){
        return a.second < b.second;
    });
    cout<<"\n Topper Student:"<<topper->first<<" with average "<<topper->second<<"."<<endl;
    return 0;
}
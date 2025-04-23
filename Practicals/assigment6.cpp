#include <iostream>
using namespace std;

class Person
{
    protected:
        string name;
        int age;
    public:
        Person(string name_person,int age_person):name(name_person),age(age_person){};
        virtual void display()
        {

        }
};

class Student:public Person
{
    int rollNumber;
    string branch;
    int marks;
    public:
        void calculate_CGPA()
        {

        }
        void display(){}
};

class Faculty:public Person
{
     int facultyID;
     string department;
     int salary;
     void display(){}
};

class TeachingAssistant:public Student,public Faculty
{

};

class Administration
{

};
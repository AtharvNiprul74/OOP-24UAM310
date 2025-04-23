#include <iostream>
using namespace std;

//base class
class Person
{
    protected:
        string name;
        int age;
    public:
        Person(string name_person,int age_person):name(name_person),age(age_person){};
        virtual void display()
        {
            cout << "Name:" << name << ",Age:" << age << endl;
        }
};

//student derived class
class Student:virtual public Person
{ 
    protected:
        int rollNumber;
        string branch;
        float marks;
    public:
        Student(string stud_nm, int stud_age, int roll, string bran, int mark): Person(stud_nm,stud_age),rollNumber(roll),branch(bran),marks(mark) {}
        float calculate_CGPA()
        {
            return marks/10;
        }
        void display() override 
        {
            cout << "Student Details:" << endl;
            Person::display();
            cout << "Roll Number:" << rollNumber << "\nBranch:" << branch << endl;
            cout << "Marks:" << marks <<", CGPA:" << calculate_CGPA();
        }
        friend class Administration;
};

//Faculty derived class
class Faculty:virtual public Person
{
    protected:
         int facultyID;
         string department;
         int salary;
    public:
         Faculty(string faculty_nm, int faculty_age, int f_id, string f_dept,int f_salary):Person(faculty_nm,faculty_age),facultyID(f_id),department(f_dept),salary(f_salary){}
         void display() override
         {
             cout << "\nFaculty Details:" << endl;
             Person::display();
             cout << "Faculty ID:" << facultyID << "\nDepartment:" << department << "\nSalary:" << salary << endl;
         }
         friend class Administration;
};

//multiple inheritance derived from student and faculty
class TeachingAssistant:public Student,public Faculty
{
     public:
         TeachingAssistant(string n, int a, int roll, string branch,float marks,int id, string dept, int sal):
         Person(n,a),Student(n,a,roll,branch,marks),Faculty(n,a,id,dept,sal){}
         
         void display() override
         {
             cout << "Teaching Assistant Details:" << endl;
             Person::display();
             cout << "Roll No:" << rollNumber << "\nBranch:" << branch << "\nFaculty ID:" << facultyID << "\nDepartment:" << department << "\nSalary:" << salary << endl;
         }
};

//Administration friend class
class Administration
{
    public:
        void access(const Student& s, const Faculty& f) 
        {
            cout << "Administration Friend Function:" << endl;
            cout << "Student " << s.name<<" from "<< s.branch <<" scored "<< s.marks<<" marks"<< endl;
            cout << "Faculty " << f.name<< " teaches"<< f.department <<endl;
        }
};

int main() 
{
    //creating objects
    Student stud("Atharv", 20,310,"cse", 90);
    Faculty facut("Abs",45, 1027," cse", 150000);
    TeachingAssistant t("Xyz", 30,3753,"CSE", 90,2754,"AI",50000);
    //displaying virtual functions
    stud.display();
    cout << endl;
    facut.display();
    cout << endl;
    t.display();
    cout << endl;
    //Administration function
    Administration admin;
    admin.access(stud,facut);
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person()
    {
        name = "null";
        age = 0;
    }

    ~Person() {}

    void setName(string n)
    {
        name = n;
    }
    void setAge(int a)
    {
        age = a;
    }

    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
};


class Student : public Person
{
private:
    int studentID;
    string courseName;
    double grade;

public:
    Student() {
        studentID = 0;
        courseName = "null";
        grade = 0;
    }
    virtual void display() {
        cout << "Default student display." << endl;
    }


    void setStudentID(int id)
    {
        studentID = id;
    }
    int getStudentID()
    {
        return studentID;
    }

    void setCourseName(string c)
    {
        courseName = c;
    }
    string getCourseName()
    {
        return courseName;
    }

    void setGrade(double g)
    {
        grade = g;
    }
    double getGrade()
    {
        return grade;
    }

    double calculateGPA()
    {
        return grade;
    }
};

class UndergraduateStudent : public Student
{
private:
    int year;

public:
    UndergraduateStudent() {
        year = 1;
    }

    void setYear(int y)
    {
        year = y;
    }
    int getYear()
    {
        return year;
    }

    void display()
    {
        cout << endl;
        cout << "========== Undergraduate Student ==========" << endl;
        cout << "Name : " << getName() << endl;
        cout << "Age  : " << getAge() << endl;
        cout << "Student ID : " << getStudentID() << endl;
        cout << "Course : " << getCourseName() << endl;
        cout << "Grade  : " << getGrade() << endl;
        cout << "GPA : " << calculateGPA() << endl;
        cout << "Year : " << year << endl;
    }
};

class PostgraduateStudent : public Student
{
private:
    string thesis;

public:
    PostgraduateStudent() {
        thesis = "null";
    }

    void setThesis(string t)
    {
        thesis = t;
    }
    string getThesis()
    {
        return thesis;
    }

    void display()
    {
        cout << endl;
        cout << "========== Postgraduate Student ==========" << endl;
        cout << "Name : " << getName() << endl;
        cout << "Age  : " << getAge() << endl;
        cout << "Student ID : " << getStudentID() << endl;
        cout << "Course : " << getCourseName() << endl;
        cout << "Grade  : " << getGrade() << endl;
        cout << "GPA : " << calculateGPA() << endl;
        cout << "Thesis : " << thesis << endl;
    }
};

int main()
{
    UndergraduateStudent uStudent;
    PostgraduateStudent pStudent;
    Student* studentPtr;

    bool undergradAdded = false;
    bool postgradAdded = false;

    int choice;
    do
    {
        cout << endl;
        cout << "====================================" << endl;
        cout << "     STUDENT MANAGEMENT SYSTEM      " << endl;
        cout << "====================================" << endl;
        cout << "1. Add Undergraduate Student" << endl;
        cout << "2. Add Postgraduate Student" << endl;
        cout << "3. Display Undergraduate Student" << endl;
        cout << "4. Display Postgraduate Student" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string name, course;
            int age, id, year;
            double grade;

            cout << endl;
            cout << "====== Add Undergraduate Student ======" << endl;
            cout << "Name: "; cin >> name;
            cout << "Age: "; cin >> age;
            cout << "Student ID: "; cin >> id;
            cout << "Course Name: "; cin >> course;
            cout << "Grade: "; cin >> grade;
            cout << "Year: "; cin >> year;

            uStudent.setName(name);
            uStudent.setAge(age);
            uStudent.setStudentID(id);
            uStudent.setCourseName(course);
            uStudent.setGrade(grade);
            uStudent.setYear(year);

            undergradAdded = true;
            cout << "Student Added Successfully!" << endl;
        }
        else if (choice == 2)
        {
            string name, course, thesis;
            int age, id;
            double grade;

            cout << endl;
            cout << "====== Add Postgraduate Student ======" << endl;
            cout << "Name: "; cin >> name;
            cout << "Age: "; cin >> age;
            cout << "Student ID: "; cin >> id;
            cout << "Course Name: "; cin >> course;
            cout << "Grade: "; cin >> grade;
            cout << "Thesis: "; cin >> thesis;

            pStudent.setName(name);
            pStudent.setAge(age);
            pStudent.setStudentID(id);
            pStudent.setCourseName(course);
            pStudent.setGrade(grade);
            pStudent.setThesis(thesis);

            postgradAdded = true;
            cout << "Postgraduate Student Added Successfully!" << endl;
        }
        else if (choice == 3)
        {
            if (undergradAdded == false) {
                cout << "\nNo Undergraduate Student Added Yet." << endl;
            }
            else {
                studentPtr = &uStudent;
                studentPtr->display();
            }
        }
        else if (choice == 4)
        {
            if (postgradAdded == false) {
                cout << "\nNo Postgraduate Student Added Yet." << endl;
            }
            else {
                studentPtr = &pStudent;
                studentPtr->display();
            }
        }
        else if (choice == 0)
        {
            cout << "Program Ended." << endl;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
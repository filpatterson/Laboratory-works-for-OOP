#include <iostream>
#include <vector>
using namespace std;

class Student
{
    string name;
    int age;
    float mark;
public:
    Student(string someName, int someAge, float someMark):name(someName), age(someAge), mark(someMark){};

    Student()
    {
        cout << "-------------------------------------------------------------\n";
        
        cout << "Input name of the student:\t";
        cin >> name;

        cout << "Input age of the student:\t";
        cin >> age;

        cout << "Input mark that student has:\t";
        cin >> mark;
    }

    float getMark()
    {
        return mark;
    }

    void showStudent()
    {
        cout << "\t" << "Name: " << name << "\tAge: " << age << "\tMark: " << mark << endl;
    }
};

class University
{
    string name;
    int foundationYear;
    vector<Student> listOfStudents;
public:

    University(string someName, int someFoundationYear): name(someName), foundationYear(someFoundationYear) {};

    void addSomeStudent(Student someStudent)
    {
        listOfStudents.push_back(someStudent);
    }

    void addListOfStudents(vector<Student> &someListOfStudents)
    {
        listOfStudents.insert(listOfStudents.begin(), someListOfStudents.begin(), someListOfStudents.end());
    } 

    float mediumMark()
    {
        float mediumMark = 0;

        for(vector<Student>::size_type i = 0; i != listOfStudents.size(); i++)
        {
            mediumMark += listOfStudents[i].getMark();
        }

        return mediumMark /= listOfStudents.size();
    }

    void showListOfStudent()
    {
        cout << "----------------------------------------------------------------------\n";
        
        cout << "\t List of students:" << endl;

        for(vector<Student>::size_type i = 0; i != listOfStudents.size(); i++)
        {
            listOfStudents[i].showStudent();
        }
    }
};

int main()
{
    University utm("UTM", 1965), asem("ASEM", 1955), ulim("ULIM", 1990);
    vector<Student> someListStud;

    Student firstStud("Petru", 20, 9.5);
    Student secondStud("Colin", 21, 8.5);
    Student thirdStud("Dmitrii", 19, 9.0);
    Student fourthStud("Ed", 20, 8.9);
    Student fifthStud("Liza", 23, 7.8);
    Student sixthStud("Beth", 22, 9.0);
    Student seventhStud("Kevin", 25, 5.6);
    Student eighthStud("Matt", 18, 7.3);
    Student ninethStud("Simon", 17, 7.6);
    Student tenthStud("Garfunkel", 20, 8.2);
    Student eleventhStud("Peter", 21, 5.5);

    utm.addSomeStudent(firstStud);
    utm.addSomeStudent(secondStud);
    utm.addSomeStudent(thirdStud);
    utm.addSomeStudent(fourthStud);
    utm.addSomeStudent(fifthStud);

    asem.addSomeStudent(sixthStud);
    asem.addSomeStudent(seventhStud);
    asem.addSomeStudent(eighthStud);

    someListStud.push_back(ninethStud);
    someListStud.push_back(tenthStud);
    someListStud.push_back(eleventhStud);

    ulim.addListOfStudents(someListStud);

    utm.showListOfStudent();
    asem.showListOfStudent();
    ulim.showListOfStudent();
}
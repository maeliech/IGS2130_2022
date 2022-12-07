#include <iostream>
using namespace std;

class Person {
private:
    const char* m_name;
    const char* m_gender;
    const char* m_birth;
public:
    Person(const char* name, const char* gender, const char* birth)
        : m_name{name}, m_gender{gender}, m_birth{birth} {}
    void virtual Info() {
        cout << "Name: " << m_name << endl;
        cout << "Gender: " << m_gender << ", Date of birth: " << m_birth << endl;
    }
};

class UniStudent : public Person {
private:
    int m_GradYear;
    const char* m_major;
public:
    UniStudent(const char* name, const char* gender, const char* birth, int gradyear, const char* major) //constructor
        : Person{ name, gender, birth }, m_GradYear{ gradyear }, m_major{ major } {}
    void virtual Info() {
        cout << "Graduation year: " << m_GradYear << ", Major: " << m_major << endl;
    }
};

class Employee : public Person {
private:
    int m_ID;
    float m_salary;
public:
    Employee(const char* name, const char* gender, const char* birth, int id, float salary)
        : Person{ name, gender, birth }, m_ID{ id }, m_salary{ salary } {}
    void virtual Info() {
        cout << "Employee ID: " << m_ID << ", Hourly salary: " << m_salary << endl;
    }
};

const int nbuf = 3;
int main() {
    // Person: name, gender, date of birth
    Person James{ "James", "Male", "Jan 1, 1980" };
    // University Student: name, gender, date of birth, graudation year, major
    UniStudent Alice{ "Alice", "Female", "Jan 1, 2002", 2026, "ISE" };
    // Employee: name, gender, date of birth, employee ID, hourly salary
    Employee Victor{ "Victor", "Male", "Jan 1, 1995", 123456, 20.5 };

    Person* member[nbuf] = { &James, &Alice, &Victor };
    int i;
    for (i = 0; i < nbuf; ++i) {
        cout << "===================== info. of our member ";
        cout << i + 1 << " =====================" << endl;
        member[i]->Info();
    }

    return 0;
}

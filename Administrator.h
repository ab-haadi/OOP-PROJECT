#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"
#include <vector>
#include <string>
using namespace std;

class Course;
class Student;

class Administrator : public User {
private:
    vector<Course*> allCourses;
    vector<Student*> allStudents;

public:
    Administrator(int id, const string& name, const string& password);

    void login() override;
    void displayMenu() override;
    string getUserType() const override;

    void addCourse(const string& courseID, const string& courseName);
    void listAllStudents();
    void viewFeeStatus(char status);
    void addStudent(Student* student);
    void listAllCourses();
};

#endif
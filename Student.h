#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

class Course;
class Assignment;

class Student : public User {
private:
    vector<Course*> enrolledCourses;
    map<Course*, string> grades;
    char feeStatus;
    double gpa;

public:
    Student(int id, const string& name, const string& password);
    ~Student();

    void login() override;
    void displayMenu() override;
    string getUserType() const override;

    void enrollCourse(Course* course);
    void submitAssignment(Assignment* assignment);
    void calculateGPA();
    void payFees();
    void viewGrades();
    void viewEnrolledCourses();

    char getFeeStatus() const;
    void setGrade(Course* course, const string& grade);
    string getGrade(Course* course) const;
};

#endif
#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Course.h"
#include "Assignment.h"
#include <vector>
#include <map>
#include <iomanip>

class Student : public User {
private:
    vector<Course*> enrolledCourses;
    map<Course*, string> grades;
    char feeStatus;
    double gpa;

public:
    Student(int id, string name, string password);
    ~Student();

    // Override pure virtual functions
    void login() override;
    void displayMenu() override;

    // Student-specific methods
    void enrollCourse(Course* course);
    void submitAssignment(Assignment* assignment);
    void calculateGPA();
    void payFees();
    void viewGrades();
    void viewEnrolledCourses();

    // Getters and setters
    char getFeeStatus() const;
    void setGrade(Course* course, string grade);
    string getGrade(Course* course) const;

protected:
    string getUserTypeString() const override;
};

#endif
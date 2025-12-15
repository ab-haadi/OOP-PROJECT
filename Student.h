#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <vector>
#include <map>
#include <string>

// Forward declarations
class Course;
class Assignment;

class Student : public User {
private:
    std::vector<Course*> enrolledCourses;
    std::map<Course*, std::string> grades;
    char feeStatus;
    double gpa;

public:
    Student(int id, const std::string& name, const std::string& password);
    ~Student();

    // Override pure virtual functions
    void login() override;
    void displayMenu() override;
    std::string getUserType() const override;

    // Student-specific methods
    void enrollCourse(Course* course);
    void submitAssignment(Assignment* assignment);
    void calculateGPA();
    void payFees();
    void viewGrades();
    void viewEnrolledCourses();

    // Getters and setters
    char getFeeStatus() const;
    void setGrade(Course* course, const std::string& grade);
    std::string getGrade(Course* course) const;
};

#endif
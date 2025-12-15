#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"
#include "Course.h"
#include "Student.h"
#include <vector>

class Administrator : public User {
private:
    vector<Course*> allCourses;
    vector<Student*> allStudents;

public:
    Administrator(int id, string name, string password);

    // Override pure virtual functions
    void login() override;
    void displayMenu() override;

    // Administrator-specific methods
    void addCourse(string courseID, string courseName);
    void listAllStudents();
    void viewFeeStatus(char status);
    void addStudent(Student* student);
    void listAllCourses();

protected:
    string getUserTypeString() const override;
};

#endif
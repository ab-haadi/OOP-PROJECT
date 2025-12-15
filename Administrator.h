#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"
#include <vector>
#include <string>

// Forward declarations
class Course;
class Student;

class Administrator : public User {
private:
    std::vector<Course*> allCourses;
    std::vector<Student*> allStudents;

public:
    Administrator(int id, const std::string& name, const std::string& password);

    // Override pure virtual functions
    void login() override;
    void displayMenu() override;
    std::string getUserType() const override;

    // Administrator-specific methods
    void addCourse(const std::string& courseID, const std::string& courseName);
    void listAllStudents();
    void viewFeeStatus(char status);
    void addStudent(Student* student);
    void listAllCourses();
};

#endif
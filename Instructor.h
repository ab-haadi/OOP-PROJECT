#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "User.h"
#include <vector>
#include <string>

// Forward declarations
class Course;
class Student;
class Assignment;

class Instructor : public User {
private:
    std::vector<Course*> teachingCourses;

public:
    Instructor(int id, const std::string& name, const std::string& password);

    // Override pure virtual functions
    void login() override;
    void displayMenu() override;
    std::string getUserType() const override;

    // Instructor-specific methods
    void createAssignment(Course* course, const std::string& details, const std::string& deadline);
    void gradeStudent(Student* student, Course* course, const std::string& grade);
    void viewClassList(Course* course);
    void addTeachingCourse(Course* course);
};

#endif
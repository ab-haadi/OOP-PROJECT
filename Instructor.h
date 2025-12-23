#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "User.h"
#include <vector>
#include <string>

using namespace std;

// Forward declarations
class Course;
class Student;
class Assignment;

class Instructor : public User {
private:
    vector<Course*> teachingCourses;

public:
    Instructor(int id, const string& name, const string& password);

    void login() override;
    void displayMenu() override;
    string getUserType() const override;

    void createAssignment(Course* course, const string& details, const string& deadline);
    void gradeStudent(Student* student, Course* course, const string& grade);
    void viewClassList(Course* course);
    void addTeachingCourse(Course* course);
};

#endif
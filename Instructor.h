#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "User.h"
#include "Course.h"
#include "Assignment.h"
#include "Student.h"
#include <vector>

class Instructor : public User {
private:
    vector<Course*> teachingCourses;

public:
    Instructor(int id, string name, string password);

    // Override pure virtual functions
    void login() override;
    void displayMenu() override;

    // Instructor-specific methods
    void createAssignment(Course* course, string details, string deadline);
    void gradeStudent(Student* student, Course* course, string grade);
    void viewClassList(Course* course);
    void addTeachingCourse(Course* course);

protected:
    string getUserTypeString() const override;
};

#endif
#ifndef COURSE_H
#define COURSE_H

#include "Instructor.h"
#include "Assignment.h"
#include "Student.h"
#include <vector>
#include <string>

class Course {
private:
    string courseID;
    string courseName;
    Instructor* instructor;
    vector<Student*> enrolledStudents;
    vector<Assignment*> assignments;

public:
    Course(string id, string name);
    ~Course();

    // Getters
    string getCourseID() const;
    string getCourseName() const;
    Instructor* getInstructor() const;
    vector<Student*> getEnrolledStudents() const;

    // Setters
    void setInstructor(Instructor* instr);

    // Course management methods
    void addStudent(Student* student);
    void removeStudent(Student* student);
    void listEnrolledStudents() const;
    void addAssignment(Assignment* assignment);
    void listAssignments() const;

    // Utility methods
    bool isStudentEnrolled(Student* student) const;
};

#endif
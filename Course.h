#ifndef COURSE_H
#define COURSE_H

#include <vector>
#include <string>

using namespace std;

// Forward declarations
class Instructor;
class Student;
class Assignment;

class Course {
private:
    string courseID;
    string courseName;
    Instructor* instructor;
    vector<Student*> enrolledStudents;
    vector<Assignment*> assignments;

public:
    Course(const string& id, const string& name);
    ~Course();

    // Getters
    string getCourseID() const;
    string getCourseName() const;
    Instructor* getInstructor() const;
    vector<Student*> getEnrolledStudents() const;

    void setInstructor(Instructor* instr);

    void addStudent(Student* student);
    void removeStudent(Student* student);
    void listEnrolledStudents() const;
    void addAssignment(Assignment* assignment);
    void listAssignments() const;

    bool isStudentEnrolled(Student* student) const;
};

#endif
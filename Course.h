#ifndef COURSE_H
#define COURSE_H

#include <vector>
#include <string>

// Forward declarations
class Instructor;
class Student;
class Assignment;

class Course {
private:
    std::string courseID;
    std::string courseName;
    Instructor* instructor;
    std::vector<Student*> enrolledStudents;
    std::vector<Assignment*> assignments;

public:
    Course(const std::string& id, const std::string& name);
    ~Course();

    // Getters
    std::string getCourseID() const;
    std::string getCourseName() const;
    Instructor* getInstructor() const;
    std::vector<Student*> getEnrolledStudents() const;

    // Setters
    void setInstructor(Instructor* instr);

    // Course management
    void addStudent(Student* student);
    void removeStudent(Student* student);
    void listEnrolledStudents() const;
    void addAssignment(Assignment* assignment);
    void listAssignments() const;

    // Utility
    bool isStudentEnrolled(Student* student) const;
};

#endif
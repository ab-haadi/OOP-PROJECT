#include "Course.h"
#include "Instructor.h"
#include "Student.h"
#include "Assignment.h"
#include <iostream>

using namespace std;

Course::Course(const string& id, const string& name)
    : courseID(id), courseName(name), instructor(nullptr) {
}

Course::~Course() {
    for (auto assignment : assignments) {
        delete assignment;
    }
    assignments.clear();
    enrolledStudents.clear();
}

string Course::getCourseID() const {
    return courseID;
}

string Course::getCourseName() const {
    return courseName;
}

Instructor* Course::getInstructor() const {
    return instructor;
}

vector<Student*> Course::getEnrolledStudents() const {
    return enrolledStudents;
}

void Course::setInstructor(Instructor* instr) {
    instructor = instr;
}

void Course::addStudent(Student* student) {
    if (!isStudentEnrolled(student)) {
        enrolledStudents.push_back(student);
    }
}

void Course::removeStudent(Student* student) {
    for (auto it = enrolledStudents.begin(); it != enrolledStudents.end(); ++it) {
        if (*it == student) {
            enrolledStudents.erase(it);
            break;
        }
    }
}

void Course::listEnrolledStudents() const {
    cout << "\n=== ENROLLED STUDENTS IN " << courseName << " ===\n";
    if (enrolledStudents.empty()) {
        cout << "No students enrolled.\n";
        return;
    }

    for (size_t i = 0; i < enrolledStudents.size(); ++i) {
        cout << i + 1 << ". " << enrolledStudents[i]->getName()
            << " (ID: " << enrolledStudents[i]->getUserID() << ")\n";
    }
    cout << "Total: " << enrolledStudents.size() << " student(s)\n";
}

void Course::addAssignment(Assignment* assignment) {
    assignments.push_back(assignment);
}

void Course::listAssignments() const {
    cout << "\n=== ASSIGNMENTS FOR " << courseName << " ===\n";
    if (assignments.empty()) {
        cout << "No assignments.\n";
        return;
    }

    for (size_t i = 0; i < assignments.size(); ++i) {
        cout << i + 1 << ". " << assignments[i]->getDescription()
            << " (Due: " << assignments[i]->getDeadline() << ")\n";
    }
    cout << "Total: " << assignments.size() << " assignment(s)\n";
}

bool Course::isStudentEnrolled(Student* student) const {
    for (auto enrolled : enrolledStudents) {
        if (enrolled == student) {
            return true;
        }
    }
    return false;
}
#include "Instructor.h"
#include <iostream>

Instructor::Instructor(int id, string name, string password)
    : User(id, name, password) {
}

void Instructor::login() {
    cout << "\n=== INSTRUCTOR LOGIN ===\n";
    cout << "Welcome, Prof. " << name << " (ID: " << userID << ")\n";
    cout << "Courses Teaching: " << teachingCourses.size() << "\n";
}

void Instructor::displayMenu() {
    cout << "\n=== INSTRUCTOR DASHBOARD ===\n";
    cout << "1. Create Assignment\n";
    cout << "2. Grade Student\n";
    cout << "3. View Class List\n";
    cout << "4. View Teaching Courses\n";
    cout << "5. Logout\n";
    cout << "Enter your choice: ";
}

void Instructor::createAssignment(Course* course, string details, string deadline) {
    Assignment* assignment = new Assignment(details, deadline, course);
    course->addAssignment(assignment);
    cout << "Assignment created for " << course->getCourseName() << "\n";
}

void Instructor::gradeStudent(Student* student, Course* course, string grade) {
    student->setGrade(course, grade);
    cout << "Grade " << grade << " assigned to " << student->getName()
        << " for " << course->getCourseName() << "\n";
}

void Instructor::viewClassList(Course* course) {
    cout << "\n=== CLASS LIST: " << course->getCourseName() << " ===\n";
    vector<Student*> students = course->getEnrolledStudents();

    if (students.empty()) {
        cout << "No students enrolled.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        cout << i + 1 << ". " << students[i]->getName()
            << " (ID: " << students[i]->getUserID() << ")\n";
        cout << "   Grade: " << students[i]->getGrade(course) << "\n";
        cout << "   Fee Status: "
            << (students[i]->getFeeStatus() == 'P' ? "PAID" : "UNPAID") << "\n";
    }
}

void Instructor::addTeachingCourse(Course* course) {
    teachingCourses.push_back(course);
}

string Instructor::getUserTypeString() const {
    return "Instructor";
}
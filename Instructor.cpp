#include "Instructor.h"
#include "Course.h"
#include "Student.h"
#include "Assignment.h"
#include <iostream>
#include <limits>

Instructor::Instructor(int id, const std::string& name, const std::string& password)
    : User(id, name, password) {
}

void Instructor::login() {
    std::cout << "\n=== INSTRUCTOR LOGIN ===\n";
    std::cout << "Welcome, Prof. " << getName() << " (ID: " << getUserID() << ")\n";
    std::cout << "Courses Teaching: " << teachingCourses.size() << "\n";
}

void Instructor::displayMenu() {
    std::cout << "\n=== INSTRUCTOR DASHBOARD ===\n";
    std::cout << "1. Create Assignment\n";
    std::cout << "2. Grade Student\n";
    std::cout << "3. View Class List\n";
    std::cout << "4. View Teaching Courses\n";
    std::cout << "5. Logout\n";
    std::cout << "=============================\n";
    std::cout << "Enter your choice: ";
}

std::string Instructor::getUserType() const {
    return "Instructor";
}

void Instructor::createAssignment(Course* course, const std::string& details, const std::string& deadline) {
    Assignment* assignment = new Assignment(details, deadline, course);
    course->addAssignment(assignment);
    std::cout << "Assignment created for " << course->getCourseName() << "\n";
}

void Instructor::gradeStudent(Student* student, Course* course, const std::string& grade) {
    student->setGrade(course, grade);
    std::cout << "Grade " << grade << " assigned to " << student->getName()
        << " for " << course->getCourseName() << "\n";
}

void Instructor::viewClassList(Course* course) {
    std::cout << "\n=== CLASS LIST: " << course->getCourseName() << " ===\n";
    std::vector<Student*> students = course->getEnrolledStudents();

    if (students.empty()) {
        std::cout << "No students enrolled.\n";
        return;
    }

    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << i + 1 << ". " << students[i]->getName()
            << " (ID: " << students[i]->getUserID() << ")\n";
        std::cout << "   Grade: " << students[i]->getGrade(course) << "\n";
        std::cout << "   Fee Status: "
            << (students[i]->getFeeStatus() == 'P' ? "PAID" : "UNPAID") << "\n";
    }
}

void Instructor::addTeachingCourse(Course* course) {
    teachingCourses.push_back(course);
}
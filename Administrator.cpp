#include "Administrator.h"
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <limits>

Administrator::Administrator(int id, const std::string& name, const std::string& password)
    : User(id, name, password) {
}

void Administrator::login() {
    std::cout << "\n=== ADMINISTRATOR LOGIN ===\n";
    std::cout << "Welcome, Admin " << getName() << " (ID: " << getUserID() << ")\n";
}

void Administrator::displayMenu() {
    std::cout << "\n=== ADMINISTRATOR DASHBOARD ===\n";
    std::cout << "1. Add New Course\n";
    std::cout << "2. List All Students\n";
    std::cout << "3. View Paid Students\n";
    std::cout << "4. View Unpaid Students\n";
    std::cout << "5. List All Courses\n";
    std::cout << "6. Logout\n";
    std::cout << "================================\n";
    std::cout << "Enter your choice: ";
}

std::string Administrator::getUserType() const {
    return "Administrator";
}

void Administrator::addCourse(const std::string& courseID, const std::string& courseName) {
    Course* newCourse = new Course(courseID, courseName);
    allCourses.push_back(newCourse);
    std::cout << "Course added: " << courseName << " (" << courseID << ")\n";
}

void Administrator::listAllStudents() {
    std::cout << "\n=== ALL REGISTERED STUDENTS ===\n";
    if (allStudents.empty()) {
        std::cout << "No students registered.\n";
        return;
    }

    for (size_t i = 0; i < allStudents.size(); ++i) {
        std::cout << i + 1 << ". " << allStudents[i]->getName()
            << " (ID: " << allStudents[i]->getUserID() << ")\n";
        std::cout << "   Fee Status: "
            << (allStudents[i]->getFeeStatus() == 'P' ? "PAID" : "UNPAID") << "\n";
    }
}

void Administrator::viewFeeStatus(char status) {
    std::string statusStr = (status == 'P') ? "PAID" : "UNPAID";
    std::cout << "\n=== STUDENTS WITH " << statusStr << " FEES ===\n";

    int count = 0;
    for (size_t i = 0; i < allStudents.size(); ++i) {
        if (allStudents[i]->getFeeStatus() == status) {
            std::cout << ++count << ". " << allStudents[i]->getName()
                << " (ID: " << allStudents[i]->getUserID() << ")\n";
        }
    }

    if (count == 0) {
        std::cout << "No students with " << statusStr << " fees.\n";
    }
}

void Administrator::addStudent(Student* student) {
    allStudents.push_back(student);
}

void Administrator::listAllCourses() {
    std::cout << "\n=== ALL COURSES ===\n";
    if (allCourses.empty()) {
        std::cout << "No courses available.\n";
        return;
    }

    for (size_t i = 0; i < allCourses.size(); ++i) {
        std::cout << i + 1 << ". " << allCourses[i]->getCourseName()
            << " (" << allCourses[i]->getCourseID() << ")\n";
    }
}
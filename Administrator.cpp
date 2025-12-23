#include "Administrator.h"
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <limits>

using namespace std;

Administrator::Administrator(int id, const string& name, const string& password)
    : User(id, name, password) {
}

void Administrator::login() {
    cout << "\n=== ADMINISTRATOR LOGIN ===\n";
    cout << "Welcome, Admin " << getName() << " (ID: " << getUserID() << ")\n";
}

void Administrator::displayMenu() {
    cout << "\n=== ADMINISTRATOR DASHBOARD ===\n";
    cout << "1. Add New Course\n";
    cout << "2. List All Students\n";
    cout << "3. View Paid Students\n";
    cout << "4. View Unpaid Students\n";
    cout << "5. List All Courses\n";
    cout << "6. Logout\n";
    cout << "================================\n";
    cout << "Enter your choice: ";
}

string Administrator::getUserType() const {
    return "Administrator";
}

void Administrator::addCourse(const string& courseID, const string& courseName) {
    Course* newCourse = new Course(courseID, courseName);
    allCourses.push_back(newCourse);
    cout << "Course added: " << courseName << " (" << courseID << ")\n";
}

void Administrator::listAllStudents() {
    cout << "\n=== ALL REGISTERED STUDENTS ===\n";
    if (allStudents.empty()) {
        cout << "No students registered.\n";
        return;
    }

    for (size_t i = 0; i < allStudents.size(); ++i) {
        cout << i + 1 << ". " << allStudents[i]->getName()
            << " (ID: " << allStudents[i]->getUserID() << ")\n";
        cout << "   Fee Status: "
            << (allStudents[i]->getFeeStatus() == 'P' ? "PAID" : "UNPAID") << "\n";
    }
}

void Administrator::viewFeeStatus(char status) {
    string statusStr = (status == 'P') ? "PAID" : "UNPAID";
    cout << "\n=== STUDENTS WITH " << statusStr << " FEES ===\n";

    int count = 0;
    for (size_t i = 0; i < allStudents.size(); ++i) {
        if (allStudents[i]->getFeeStatus() == status) {
            cout << ++count << ". " << allStudents[i]->getName()
                << " (ID: " << allStudents[i]->getUserID() << ")\n";
        }
    }

    if (count == 0) {
        cout << "No students with " << statusStr << " fees.\n";
    }
    else {
        cout << "Total: " << count << " student(s)\n";
    }
}

void Administrator::addStudent(Student* student) {
    allStudents.push_back(student);
}

void Administrator::listAllCourses() {
    cout << "\n=== ALL COURSES ===\n";
    if (allCourses.empty()) {
        cout << "No courses available.\n";
        return;
    }

    for (size_t i = 0; i < allCourses.size(); ++i) {
        cout << i + 1 << ". " << allCourses[i]->getCourseName()
            << " (" << allCourses[i]->getCourseID() << ")\n";
    }
    cout << "Total: " << allCourses.size() << " course(s)\n";
}
#include "Administrator.h"
#include <iostream>

Administrator::Administrator(int id, string name, string password)
    : User(id, name, password) {
}

void Administrator::login() {
    cout << "\n=== ADMINISTRATOR LOGIN ===\n";
    cout << "Welcome, Admin " << name << " (ID: " << userID << ")\n";
}

void Administrator::displayMenu() {
    cout << "\n=== ADMINISTRATOR DASHBOARD ===\n";
    cout << "1. Add New Course\n";
    cout << "2. List All Students\n";
    cout << "3. View Paid Students\n";
    cout << "4. View Unpaid Students\n";
    cout << "5. List All Courses\n";
    cout << "6. Logout\n";
    cout << "Enter your choice: ";
}

void Administrator::addCourse(string courseID, string courseName) {
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

    for (int i = 0; i < allStudents.size(); i++) {
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
    for (int i = 0; i < allStudents.size(); i++) {
        if (allStudents[i]->getFeeStatus() == status) {
            cout << ++count << ". " << allStudents[i]->getName()
                << " (ID: " << allStudents[i]->getUserID() << ")\n";
        }
    }

    if (count == 0) {
        cout << "No students with " << statusStr << " fees.\n";
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

    for (int i = 0; i < allCourses.size(); i++) {
        cout << i + 1 << ". " << allCourses[i]->getCourseName()
            << " (" << allCourses[i]->getCourseID() << ")\n";
    }
}

string Administrator::getUserTypeString() const {
    return "Administrator";
}
#include "Student.h"
#include "Course.h"
#include "Assignment.h"
#include <iostream>
#include <iomanip>
#include <map>
#include <limits>
using namespace std;

Student::Student(int id, const string& name, const string& password)
    : User(id, name, password), feeStatus('U'), gpa(0.0) {
}

Student::~Student() {
    enrolledCourses.clear();
    grades.clear();
}

void Student::login() {
    cout << "\n=== STUDENT LOGIN ===\n";
    cout << "Welcome, " << getName() << " (ID: " << getUserID() << ")\n";
    cout << "Fee Status: " << (feeStatus == 'P' ? "PAID" : "UNPAID") << "\n";
    cout << "Current GPA: " << fixed << setprecision(2) << gpa << "\n";
}

void Student::displayMenu() {
    cout << "\n=== STUDENT DASHBOARD ===\n";
    cout << "1. View Enrolled Courses\n";
    cout << "2. View Grades\n";
    cout << "3. Submit Assignment\n";
    cout << "4. Calculate GPA\n";
    cout << "5. Pay Fees\n";
    cout << "6. Logout\n";
    cout << "==========================\n";
    cout << "Enter your choice: ";
}

string Student::getUserType() const {
    return "Student";
}

void Student::enrollCourse(Course* course) {
    enrolledCourses.push_back(course);
    grades[course] = "N/A";
    cout << "Successfully enrolled in " << course->getCourseName() << "\n";
}

void Student::submitAssignment(Assignment* assignment) {
    cout << "\nSubmitting assignment for: " << assignment->getDescription() << "\n";
    cout << "Course: " << assignment->getCourse()->getCourseName() << "\n";
    cout << "Deadline: " << assignment->getDeadline() << "\n";
    cout << "Assignment submitted successfully!\n";
}

void Student::calculateGPA() {
    if (enrolledCourses.empty()) {
        gpa = 0.0;
        cout << "No courses enrolled. GPA: 0.00\n";
        return;
    }

    double total = 0.0;
    int count = 0;

    map<string, double> gradePoints = {
        {"A", 4.0}, {"B+", 3.5}, {"B", 3.0}, {"C+", 2.5},
        {"C", 2.0}, {"D", 1.0}, {"F", 0.0}
    };

    for (auto& grade : grades) {
        if (grade.second != "N/A") {
            auto it = gradePoints.find(grade.second);
            if (it != gradePoints.end()) {
                total += it->second;
                count++;
            }
        }
    }

    gpa = (count > 0) ? total / count : 0.0;
    cout << "GPA calculated: " << fixed << setprecision(2) << gpa << "\n";
    cout << "Based on " << count << " graded courses\n";
}

void Student::payFees() {
    if (feeStatus == 'P') {
        cout << "Fees are already paid!\n";
        return;
    }

    feeStatus = 'P';
    cout << "Fees paid successfully!\n";
    cout << "Fee Status: PAID\n";
}

void Student::viewGrades() {
    cout << "\n=== YOUR GRADES ===\n";
    if (grades.empty()) {
        cout << "No grades available.\n";
        return;
    }

    int count = 1;
    for (auto& grade : grades) {
        cout << count++ << ". " << grade.first->getCourseName()
            << " (" << grade.first->getCourseID() << "): "
            << grade.second << "\n";
    }
}

void Student::viewEnrolledCourses() {
    cout << "\n=== ENROLLED COURSES ===\n";
    if (enrolledCourses.empty()) {
        cout << "No courses enrolled.\n";
        return;
    }

    for (size_t i = 0; i < enrolledCourses.size(); ++i) {
        cout << i + 1 << ". " << enrolledCourses[i]->getCourseName()
            << " (" << enrolledCourses[i]->getCourseID() << ")\n";
        cout << "   Grade: " << grades[enrolledCourses[i]] << "\n";
    }
}

char Student::getFeeStatus() const {
    return feeStatus;
}

void Student::setGrade(Course* course, const string& grade) {
    grades[course] = grade;
}

string Student::getGrade(Course* course) const {
    auto it = grades.find(course);
    return (it != grades.end()) ? it->second : "N/A";
}
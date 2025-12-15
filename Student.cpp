#include "Student.h"
#include "Course.h"
#include "Assignment.h"
#include <iostream>
#include <iomanip>
#include <map>

Student::Student(int id, const std::string& name, const std::string& password)
    : User(id, name, password), feeStatus('U'), gpa(0.0) {
}

Student::~Student() {
    enrolledCourses.clear();
    grades.clear();
}

void Student::login() {
    std::cout << "\n=== STUDENT LOGIN ===\n";
    std::cout << "Welcome, " << getName() << " (ID: " << getUserID() << ")\n";
    std::cout << "Fee Status: " << (feeStatus == 'P' ? "PAID" : "UNPAID") << "\n";
    std::cout << "Current GPA: " << std::fixed << std::setprecision(2) << gpa << "\n";
}

void Student::displayMenu() {
    std::cout << "\n=== STUDENT DASHBOARD ===\n";
    std::cout << "1. View Enrolled Courses\n";
    std::cout << "2. View Grades\n";
    std::cout << "3. Submit Assignment\n";
    std::cout << "4. Calculate GPA\n";
    std::cout << "5. Pay Fees\n";
    std::cout << "6. Logout\n";
    std::cout << "Enter your choice: ";
}

std::string Student::getUserType() const {
    return "Student";
}

void Student::enrollCourse(Course* course) {
    enrolledCourses.push_back(course);
    grades[course] = "N/A";
    std::cout << "Successfully enrolled in " << course->getCourseName() << "\n";
}

void Student::submitAssignment(Assignment* assignment) {
    std::cout << "\nSubmitting assignment for: " << assignment->getDescription() << "\n";
    std::cout << "Assignment submitted successfully!\n";
}

void Student::calculateGPA() {
    if (enrolledCourses.empty()) {
        gpa = 0.0;
        std::cout << "No courses enrolled. GPA: 0.00\n";
        return;
    }

    double total = 0.0;
    int count = 0;

    std::map<std::string, double> gradePoints = {
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
    std::cout << "GPA calculated: " << std::fixed << std::setprecision(2) << gpa << "\n";
}

void Student::payFees() {
    feeStatus = 'P';
    std::cout << "Fees paid successfully!\n";
    std::cout << "Fee Status: PAID\n";
}

void Student::viewGrades() {
    std::cout << "\n=== YOUR GRADES ===\n";
    if (grades.empty()) {
        std::cout << "No grades available.\n";
        return;
    }

    for (auto& grade : grades) {
        std::cout << grade.first->getCourseName() << ": " << grade.second << "\n";
    }
}

void Student::viewEnrolledCourses() {
    std::cout << "\n=== ENROLLED COURSES ===\n";
    if (enrolledCourses.empty()) {
        std::cout << "No courses enrolled.\n";
        return;
    }

    for (size_t i = 0; i < enrolledCourses.size(); ++i) {
        std::cout << i + 1 << ". " << enrolledCourses[i]->getCourseName()
            << " (" << enrolledCourses[i]->getCourseID() << ")\n";
    }
}

char Student::getFeeStatus() const {
    return feeStatus;
}

void Student::setGrade(Course* course, const std::string& grade) {
    grades[course] = grade;
}

std::string Student::getGrade(Course* course) const {
    auto it = grades.find(course);
    return (it != grades.end()) ? it->second : "N/A";
}
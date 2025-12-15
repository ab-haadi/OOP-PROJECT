#include "Student.h"
#include <iostream>

Student::Student(int id, string name, string password)
    : User(id, name, password), feeStatus('U'), gpa(0.0) {
}

Student::~Student() {
    enrolledCourses.clear();
    grades.clear();
}

void Student::login() {
    cout << "\n=== STUDENT LOGIN ===\n";
    cout << "Welcome, " << name << " (ID: " << userID << ")\n";
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
    cout << "Enter your choice: ";
}

void Student::enrollCourse(Course* course) {
    enrolledCourses.push_back(course);
    grades[course] = "N/A"; // Initialize grade as Not Available
    cout << "Successfully enrolled in " << course->getCourseName() << "\n";
}

void Student::submitAssignment(Assignment* assignment) {
    cout << "\nSubmitting assignment for: " << assignment->getDescription() << "\n";
    cout << "Assignment submitted successfully!\n";
}

void Student::calculateGPA() {
    if (enrolledCourses.empty()) {
        gpa = 0.0;
        cout << "No courses enrolled. GPA: 0.00\n";
        return;
    }

    // Simple GPA calculation (for demonstration)
    double total = 0.0;
    int count = 0;

    map<string, double> gradePoints = {
        {"A", 4.0}, {"B+", 3.5}, {"B", 3.0}, {"C+", 2.5},
        {"C", 2.0}, {"D", 1.0}, {"F", 0.0}
    };

    for (auto& grade : grades) {
        if (grade.second != "N/A") {
            total += gradePoints[grade.second];
            count++;
        }
    }

    gpa = (count > 0) ? total / count : 0.0;
    cout << "GPA calculated: " << fixed << setprecision(2) << gpa << "\n";
}

void Student::payFees() {
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

    for (auto& grade : grades) {
        cout << grade.first->getCourseName() << ": " << grade.second << "\n";
    }
}

void Student::viewEnrolledCourses() {
    cout << "\n=== ENROLLED COURSES ===\n";
    if (enrolledCourses.empty()) {
        cout << "No courses enrolled.\n";
        return;
    }

    for (int i = 0; i < enrolledCourses.size(); i++) {
        cout << i + 1 << ". " << enrolledCourses[i]->getCourseName()
            << " (" << enrolledCourses[i]->getCourseID() << ")\n";
    }
}

char Student::getFeeStatus() const {
    return feeStatus;
}

void Student::setGrade(Course* course, string grade) {
    grades[course] = grade;
}

string Student::getGrade(Course* course) const {
    auto it = grades.find(course);
    return (it != grades.end()) ? it->second : "N/A";
}

string Student::getUserTypeString() const {
    return "Student";
}
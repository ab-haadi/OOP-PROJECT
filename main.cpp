#include "User.h"
#include "Student.h"
#include "Instructor.h"
#include "Administrator.h"
#include "Course.h"
#include "Assignment.h"
#include <iostream>
#include <vector>
#include <memory>
#include <limits>

// Function prototypes
void studentLogin();
void instructorLogin();
void administratorLogin();
void createSampleData(std::vector<Course*>& courses,
    std::vector<Student*>& students,
    Administrator*& admin,
    Instructor*& instructor);

int main() {
    std::vector<Course*> courses;
    std::vector<Student*> students;
    Administrator* admin = nullptr;
    Instructor* instructor = nullptr;

    // Create sample data for testing
    createSampleData(courses, students, admin, instructor);

    int choice;

    while (true) {
        std::cout << "\n========================================\n";
        std::cout << "   LEARNING MANAGEMENT SYSTEM (LMS)    \n";
        std::cout << "========================================\n";
        std::cout << "1. Login as Student\n";
        std::cout << "2. Login as Instructor\n";
        std::cout << "3. Login as Administrator\n";
        std::cout << "4. Exit\n";
        std::cout << "========================================\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            studentLogin();
            break;
        case 2:
            instructorLogin();
            break;
        case 3:
            administratorLogin();
            break;
        case 4:
            std::cout << "Thank you for using LMS. Goodbye!\n";

            // Cleanup
            if (admin) delete admin;
            if (instructor) delete instructor;

            for (auto student : students) {
                delete student;
            }

            for (auto course : courses) {
                delete course;
            }

            return 0;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}

void studentLogin() {
    int id;
    std::string password;

    std::cout << "\n=== STUDENT LOGIN ===\n";
    std::cout << "Enter Student ID: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    std::cin >> password;

    // Hardcoded student credentials for demo
    if ((id == 3001 && password == "student123") ||
        (id == 3002 && password == "student456")) {

        Student* student;
        if (id == 3001) {
            student = new Student(3001, "Ali Khan", "student123");
        }
        else {
            student = new Student(3002, "Sara Ahmed", "student456");
        }

        student->login();

        int choice;
        do {
            student->displayMenu();

            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input! Please enter a number.\n";
                continue;
            }

            // Note: In a complete implementation, these menu options would
            // connect to actual functionality. For now, they're placeholders.
            switch (choice) {
            case 1:
                std::cout << "Viewing enrolled courses...\n";
                // student->viewEnrolledCourses();
                break;
            case 2:
                std::cout << "Viewing grades...\n";
                // student->viewGrades();
                break;
            case 3:
                std::cout << "Submitting assignment...\n";
                // student->submitAssignment();
                break;
            case 4:
                std::cout << "Calculating GPA...\n";
                // student->calculateGPA();
                break;
            case 5:
                std::cout << "Paying fees...\n";
                // student->payFees();
                break;
            case 6:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
            }

            if (choice != 6) {
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
            }

        } while (choice != 6);

        delete student;
    }
    else {
        std::cout << "Invalid credentials! Access denied.\n";
    }
}

void instructorLogin() {
    int id;
    std::string password;

    std::cout << "\n=== INSTRUCTOR LOGIN ===\n";
    std::cout << "Enter Instructor ID: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    std::cin >> password;

    // Hardcoded instructor credentials for demo
    if (id == 2001 && password == "prof123") {
        Instructor* instructor = new Instructor(2001, "Dr. Ahmed", "prof123");
        instructor->login();

        int choice;
        do {
            instructor->displayMenu();

            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input! Please enter a number.\n";
                continue;
            }

            switch (choice) {
            case 1:
                std::cout << "Creating assignment...\n";
                // instructor->createAssignment();
                break;
            case 2:
                std::cout << "Grading student...\n";
                // instructor->gradeStudent();
                break;
            case 3:
                std::cout << "Viewing class list...\n";
                // instructor->viewClassList();
                break;
            case 4:
                std::cout << "Viewing teaching courses...\n";
                // instructor->viewTeachingCourses();
                break;
            case 5:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
            }

            if (choice != 5) {
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
            }

        } while (choice != 5);

        delete instructor;
    }
    else {
        std::cout << "Invalid credentials! Access denied.\n";
    }
}

void administratorLogin() {
    int id;
    std::string password;

    std::cout << "\n=== ADMINISTRATOR LOGIN ===\n";
    std::cout << "Enter Administrator ID: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    std::cin >> password;

    // Hardcoded admin credentials for demo
    if (id == 1001 && password == "admin123") {
        Administrator* admin = new Administrator(1001, "Admin", "admin123");
        admin->login();

        int choice;
        do {
            admin->displayMenu();

            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input! Please enter a number.\n";
                continue;
            }

            switch (choice) {
            case 1:
                std::cout << "Adding new course...\n";
                // admin->addCourse();
                break;
            case 2:
                std::cout << "Listing all students...\n";
                // admin->listAllStudents();
                break;
            case 3:
                std::cout << "Viewing paid students...\n";
                // admin->viewFeeStatus('P');
                break;
            case 4:
                std::cout << "Viewing unpaid students...\n";
                // admin->viewFeeStatus('U');
                break;
            case 5:
                std::cout << "Listing all courses...\n";
                // admin->listAllCourses();
                break;
            case 6:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
            }

            if (choice != 6) {
                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
            }

        } while (choice != 6);

        delete admin;
    }
    else {
        std::cout << "Invalid credentials! Access denied.\n";
    }
}

void createSampleData(std::vector<Course*>& courses,
    std::vector<Student*>& students,
    Administrator*& admin,
    Instructor*& instructor) {
    // Create sample data for testing
    courses.push_back(new Course("CS101", "Object Oriented Programming"));
    courses.push_back(new Course("CS102", "Digital Logic Design"));
    courses.push_back(new Course("MATH101", "Applied Calculus"));

    students.push_back(new Student(3001, "Ali Khan", "student123"));
    students.push_back(new Student(3002, "Sara Ahmed", "student456"));

    admin = new Administrator(1001, "Admin", "admin123");
    instructor = new Instructor(2001, "Dr. Ahmed", "prof123");
}
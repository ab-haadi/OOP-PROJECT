#include "User.h"
#include "Student.h"
#include "Instructor.h"
#include "Administrator.h"
#include "Course.h"
#include "Assignment.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Global variables for simulation
vector<Course*> courses;
vector<Student*> students;
vector<Instructor*> instructors;
Administrator* admin = nullptr;

// Function prototypes
void initializeSystem();
void mainMenu();
void studentMenu(Student* student);
void instructorMenu(Instructor* instructor);
void adminMenu(Administrator* admin);
void cleanup();

int main() {
    cout << "========================================\n";
    cout << "   LEARNING MANAGEMENT SYSTEM (LMS)    \n";
    cout << "========================================\n";

    initializeSystem();
    mainMenu();
    cleanup();

    return 0;
}

void initializeSystem() {
    // Create administrator
    admin = new Administrator(1001, "Admin", "admin123");

    // Create some courses
    Course* oop = new Course("CS101", "Object Oriented Programming");
    Course* dld = new Course("CS102", "Digital Logic Design");
    Course* calc = new Course("MATH101", "Applied Calculus");

    courses.push_back(oop);
    courses.push_back(dld);
    courses.push_back(calc);

    // Create instructor
    Instructor* profAhmed = new Instructor(2001, "Dr. Ahmed", "prof123");
    instructors.push_back(profAhmed);

    // Assign instructor to courses
    oop->setInstructor(profAhmed);
    dld->setInstructor(profAhmed);
    profAhmed->addTeachingCourse(oop);
    profAhmed->addTeachingCourse(dld);

    // Create students
    Student* student1 = new Student(3001, "Ali Khan", "student123");
    Student* student2 = new Student(3002, "Sara Ahmed", "student456");

    students.push_back(student1);
    students.push_back(student2);

    // Register admin students
    admin->addStudent(student1);
    admin->addStudent(student2);

    // Enroll students in courses
    student1->enrollCourse(oop);
    student1->enrollCourse(calc);
    student2->enrollCourse(dld);
    student2->enrollCourse(calc);

    oop->addStudent(student1);
    dld->addStudent(student2);
    calc->addStudent(student1);
    calc->addStudent(student2);

    // Create sample assignment
    Assignment* oopAssignment = new Assignment(
        "Implement Banking System", "2024-12-15", oop
    );
    oop->addAssignment(oopAssignment);

    cout << "System initialized with sample data.\n";
}

void mainMenu() {
    int choice;
    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Student Login\n";
        cout << "2. Instructor Login\n";
        cout << "3. Administrator Login\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            if (!students.empty()) {
                cout << "\nSelect student:\n";
                for (int i = 0; i < students.size(); i++) {
                    cout << i + 1 << ". " << students[i]->getName()
                        << " (ID: " << students[i]->getUserID() << ")\n";
                }
                int studentChoice;
                cin >> studentChoice;
                if (studentChoice > 0 && studentChoice <= students.size()) {
                    students[studentChoice - 1]->login();
                    studentMenu(students[studentChoice - 1]);
                }
            }
            break;
        }
        case 2: {
            if (!instructors.empty()) {
                instructors[0]->login();
                instructorMenu(instructors[0]);
            }
            break;
        }
        case 3: {
            if (admin != nullptr) {
                admin->login();
                adminMenu(admin);
            }
            break;
        }
        case 4:
            cout << "Exiting system...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

void studentMenu(Student* student) {
    int choice;
    do {
        student->displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            student->viewEnrolledCourses();
            break;
        case 2:
            student->viewGrades();
            break;
        case 3:
            if (!courses.empty() && !courses[0]->getEnrolledStudents().empty()) {
                student->submitAssignment(new Assignment(
                    "Sample Assignment", "2024-12-20", courses[0]
                ));
            }
            break;
        case 4:
            student->calculateGPA();
            break;
        case 5:
            student->payFees();
            break;
        case 6:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);
}

void instructorMenu(Instructor* instructor) {
    int choice;
    do {
        instructor->displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            if (!courses.empty()) {
                instructor->createAssignment(courses[0],
                    "New Project: Library Management", "2024-12-25");
            }
            break;
        case 2:
            if (!students.empty() && !courses.empty()) {
                instructor->gradeStudent(students[0], courses[0], "A");
            }
            break;
        case 3:
            if (!courses.empty()) {
                instructor->viewClassList(courses[0]);
            }
            break;
        case 4:
            cout << "\nTeaching Courses:\n";
            for (auto course : courses) {
                if (course->getInstructor() == instructor) {
                    cout << "- " << course->getCourseName() << "\n";
                }
            }
            break;
        case 5:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

void adminMenu(Administrator* admin) {
    int choice;
    do {
        admin->displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            admin->addCourse("CS103", "Data Structures");
            break;
        case 2:
            admin->listAllStudents();
            break;
        case 3:
            admin->viewFeeStatus('P');
            break;
        case 4:
            admin->viewFeeStatus('U');
            break;
        case 5:
            admin->listAllCourses();
            break;
        case 6:
            cout << "Logging out...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);
}

void cleanup() {
    // Clean up all dynamically allocated memory
    for (auto student : students) {
        delete student;
    }
    students.clear();

    for (auto instructor : instructors) {
        delete instructor;
    }
    instructors.clear();

    for (auto course : courses) {
        delete course;
    }
    courses.clear();

    if (admin != nullptr) {
        delete admin;
        admin = nullptr;
    }

    cout << "Memory cleaned up successfully.\n";
}
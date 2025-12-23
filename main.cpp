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
using namespace std;

void studentLogin(vector<Student*>& students, vector<Course*>& courses);
void instructorLogin(Instructor* instructor, vector<Course*>& courses, vector<Student*>& students);
void administratorLogin(Administrator* admin, vector<Course*>& courses, vector<Student*>& students);
void createSampleData(vector<Course*>& courses,
    vector<Student*>& students,
    Administrator*& admin,
    Instructor*& instructor);

int main() {
    vector<Course*> courses;
    vector<Student*> students;
    Administrator* admin = nullptr;
    Instructor* instructor = nullptr;

    // Create sample data for testing
    createSampleData(courses, students, admin, instructor);

    int choice;

    while (true) {
        cout << "\n========================================\n";
        cout << "   LEARNING MANAGEMENT SYSTEM (LMS)    \n";
        cout << "========================================\n";
        cout << "1. Login as Student\n";
        cout << "2. Login as Instructor\n";
        cout << "3. Login as Administrator\n";
        cout << "4. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            studentLogin(students, courses);
            break;
        case 2:
            instructorLogin(instructor, courses, students);
            break;
        case 3:
            administratorLogin(admin, courses, students);
            break;
        case 4:
            cout << "Thank you for using LMS. Goodbye!\n";

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
            cout << "Invalid choice! Please try again.\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}

void studentLogin(vector<Student*>& students, vector<Course*>& courses) {
    int id;
    string password;

    cout << "\n=== STUDENT LOGIN ===\n";
    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;

    Student* loggedStudent = nullptr;

    // Find student in the list
    for (auto student : students) {
        // For demo, just check ID (in real app, check password properly)
        if (student->getUserID() == id) {
            loggedStudent = student;
            break;
        }
    }

    if (loggedStudent) {
        loggedStudent->login();

        int choice;
        do {
            loggedStudent->displayMenu();

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number.\n";
                continue;
            }

            switch (choice) {
            case 1:
                loggedStudent->viewEnrolledCourses();
                break;
            case 2:
                loggedStudent->viewGrades();
                break;
            case 3: {
                if (courses.empty()) {
                    cout << "No courses available.\n";
                    break;
                }
                cout << "Select course to submit assignment:\n";
                for (size_t i = 0; i < courses.size(); ++i) {
                    cout << i + 1 << ". " << courses[i]->getCourseName() << endl;
                }
                int courseChoice;
                cin >> courseChoice;
                if (courseChoice > 0 && courseChoice <= courses.size()) {
                    // For demo, create a simple assignment
                    string desc;
                    cin.ignore();
                    cout << "Enter assignment description: ";
                    getline(cin, desc);
                    Assignment* assignment = new Assignment(
                        desc,
                        "2024-12-31",
                        courses[courseChoice - 1]
                    );
                    loggedStudent->submitAssignment(assignment);
                    delete assignment;
                }
                break;
            }
            case 4:
                loggedStudent->calculateGPA();
                break;
            case 5:
                loggedStudent->payFees();
                break;
            case 6:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
            }

            if (choice != 6) {
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
            }

        } while (choice != 6);
    }
    else {
        cout << "Invalid credentials! Access denied.\n";
    }
}

void instructorLogin(Instructor* instructor, vector<Course*>& courses, vector<Student*>& students) {
    int id;
    string password;

    cout << "\n=== INSTRUCTOR LOGIN ===\n";
    cout << "Enter Instructor ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;

    if (instructor->getUserID() == id) {
        instructor->login();

        int choice;
        do {
            instructor->displayMenu();

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number.\n";
                continue;
            }

            switch (choice) {
            case 1: {
                if (courses.empty()) {
                    cout << "No courses available.\n";
                    break;
                }
                cout << "Select course to create assignment:\n";
                for (size_t i = 0; i < courses.size(); ++i) {
                    cout << i + 1 << ". " << courses[i]->getCourseName() << endl;
                }
                int courseChoice;
                cin >> courseChoice;
                if (courseChoice > 0 && courseChoice <= courses.size()) {
                    string desc, deadline;
                    cin.ignore();
                    cout << "Enter assignment description: ";
                    getline(cin, desc);
                    cout << "Enter deadline (YYYY-MM-DD): ";
                    getline(cin, deadline);
                    instructor->createAssignment(courses[courseChoice - 1], desc, deadline);
                }
                break;
            }
            case 2: {
                if (students.empty() || courses.empty()) {
                    cout << "No students or courses available.\n";
                    break;
                }

                cout << "Select student to grade:\n";
                for (size_t i = 0; i < students.size(); ++i) {
                    cout << i + 1 << ". " << students[i]->getName()
                        << " (ID: " << students[i]->getUserID() << ")\n";
                }
                int studentChoice;
                cin >> studentChoice;

                cout << "Select course for grading:\n";
                for (size_t i = 0; i < courses.size(); ++i) {
                    cout << i + 1 << ". " << courses[i]->getCourseName() << endl;
                }
                int courseChoice;
                cin >> courseChoice;

                if (studentChoice > 0 && studentChoice <= students.size() &&
                    courseChoice > 0 && courseChoice <= courses.size()) {

                    string grade;
                    cin.ignore();
                    cout << "Enter grade (A, B+, B, C+, C, D, F): ";
                    getline(cin, grade);

                    instructor->gradeStudent(students[studentChoice - 1],
                        courses[courseChoice - 1],
                        grade);
                }
                break;
            }
            case 3: {
                if (courses.empty()) {
                    cout << "No courses available.\n";
                    break;
                }
                cout << "Select course to view class list:\n";
                for (size_t i = 0; i < courses.size(); ++i) {
                    cout << i + 1 << ". " << courses[i]->getCourseName() << endl;
                }
                int courseChoice;
                cin >> courseChoice;
                if (courseChoice > 0 && courseChoice <= courses.size()) {
                    instructor->viewClassList(courses[courseChoice - 1]);
                }
                break;
            }
            case 4:
                cout << "You are teaching " << courses.size() << " courses.\n";
                for (size_t i = 0; i < courses.size(); ++i) {
                    cout << i + 1 << ". " << courses[i]->getCourseName()
                        << " (" << courses[i]->getCourseID() << ")\n";
                }
                break;
            case 5:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
            }

            if (choice != 5) {
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
            }

        } while (choice != 5);
    }
    else {
        cout << "Invalid credentials! Access denied.\n";
    }
}

void administratorLogin(Administrator* admin, vector<Course*>& courses, vector<Student*>& students) {
    int id;
    string password;

    cout << "\n=== ADMINISTRATOR LOGIN ===\n";
    cout << "Enter Administrator ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;

    if (admin->getUserID() == id) {
        admin->login();

        // Add existing data to admin's lists
        for (auto student : students) {
            admin->addStudent(student);
        }

        int choice;
        do {
            admin->displayMenu();

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a number.\n";
                continue;
            }

            switch (choice) {
            case 1: {
                string courseID, courseName;
                cin.ignore();
                cout << "Enter Course ID: ";
                getline(cin, courseID);
                cout << "Enter Course Name: ";
                getline(cin, courseName);
                admin->addCourse(courseID, courseName);
                break;
            }
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
                cout << "Invalid choice! Please try again.\n";
            }

            if (choice != 6) {
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
            }

        } while (choice != 6);
    }
    else {
        cout << "Invalid credentials! Access denied.\n";
    }
}

void createSampleData(vector<Course*>& courses,
    vector<Student*>& students,
    Administrator*& admin,
    Instructor*& instructor) {

    // Create sample courses
    Course* course1 = new Course("CS101", "Object Oriented Programming");
    Course* course2 = new Course("CS102", "Digital Logic Design");
    Course* course3 = new Course("MATH101", "Applied Calculus");

    courses.push_back(course1);
    courses.push_back(course2);
    courses.push_back(course3);

    // Create sample students
    Student* student1 = new Student(3001, "Ali Khan", "student123");
    Student* student2 = new Student(3002, "Sara Ahmed", "student456");

    students.push_back(student1);
    students.push_back(student2);

    // Create admin and instructor
    admin = new Administrator(1001, "Admin", "admin123");
    instructor = new Instructor(2001, "Dr. Ahmed", "prof123");

    // Set up relationships
    course1->setInstructor(instructor);
    course2->setInstructor(instructor);
    instructor->addTeachingCourse(course1);
    instructor->addTeachingCourse(course2);

    // Enroll students in courses
    student1->enrollCourse(course1);
    student1->enrollCourse(course2);
    student2->enrollCourse(course1);
    student2->enrollCourse(course3);

    course1->addStudent(student1);
    course1->addStudent(student2);
    course2->addStudent(student1);
    course3->addStudent(student2);

    // Add some initial grades
    student1->setGrade(course1, "A");
    student1->setGrade(course2, "B+");
    student2->setGrade(course1, "B");
    student2->setGrade(course3, "A");

    // Create sample assignments
    Assignment* assignment1 = new Assignment("OOP Project", "2024-12-15", course1);
    Assignment* assignment2 = new Assignment("DLD Lab Report", "2024-12-10", course2);
    Assignment* assignment3 = new Assignment("Calculus Homework", "2024-12-05", course3);

    course1->addAssignment(assignment1);
    course2->addAssignment(assignment2);
    course3->addAssignment(assignment3);

    // Set fee status
    student1->payFees();  // Ali pays fees
    // Sara remains unpaid

    // Calculate initial GPAs
    student1->calculateGPA();
    student2->calculateGPA();
}
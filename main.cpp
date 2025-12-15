#include "User.h"
#include "Student.h"
#include "Instructor.h"
#include "Administrator.h"
#include "Course.h"
#include "Assignment.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "========================================\n";
    std::cout << "   LEARNING MANAGEMENT SYSTEM (LMS)    \n";
    std::cout << "========================================\n";

    // Create administrator
    Administrator* admin = new Administrator(1001, "Admin", "admin123");

    // Create courses
    Course* oop = new Course("CS101", "Object Oriented Programming");
    Course* dld = new Course("CS102", "Digital Logic Design");
    Course* calc = new Course("MATH101", "Applied Calculus");

    std::vector<Course*> courses = { oop, dld, calc };

    // Create instructor
    Instructor* profAhmed = new Instructor(2001, "Dr. Ahmed", "prof123");

    // Assign instructor to courses
    oop->setInstructor(profAhmed);
    dld->setInstructor(profAhmed);
    profAhmed->addTeachingCourse(oop);
    profAhmed->addTeachingCourse(dld);

    // Create students
    Student* student1 = new Student(3001, "Ali Khan", "student123");
    Student* student2 = new Student(3002, "Sara Ahmed", "student456");

    std::vector<Student*> students = { student1, student2 };

    // Register admin students
    admin->addStudent(student1);
    admin->addStudent(student2);

    // Enroll students
    student1->enrollCourse(oop);
    student1->enrollCourse(calc);
    student2->enrollCourse(dld);
    student2->enrollCourse(calc);

    oop->addStudent(student1);
    dld->addStudent(student2);
    calc->addStudent(student1);
    calc->addStudent(student2);

    // Create assignment
    Assignment* oopAssignment = new Assignment("Implement Banking System", "2024-12-15", oop);
    oop->addAssignment(oopAssignment);

    // Test the system
    std::cout << "\n=== TESTING SYSTEM ===\n";

    // Test student
    student1->login();
    student1->viewEnrolledCourses();

    // Test instructor
    profAhmed->login();
    profAhmed->createAssignment(oop, "Project 2", "2024-12-30");

    // Test admin
    admin->login();
    admin->listAllStudents();

    // Cleanup
    delete admin;
    delete profAhmed;
    delete student1;
    delete student2;

    for (auto course : courses) {
        delete course;
    }

    std::cout << "\nProgram completed successfully!\n";
    return 0;
}
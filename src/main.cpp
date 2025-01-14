#include <iostream>
#include "../Headers/node_operations.h"
#include "../Headers/fileHandler.h"
using namespace std;
/*
* Function to display menu
*/
void displayMenu() {
	cout << "\n\n";
	cout << "*****************************************************";
    cout << "\nStudent Records Management System\n";
	cout << "*****************************************************\n";
	cout << "Select an option:\n";
    cout << "1. Add Student\n";
    cout << "2. Delete Student\n";
    cout << "3. Find Student\n";
    cout << "4. Display All Students\n";
    cout << "5. Modify Student CGPA\n";
    cout << "6. Add Course to Student\n";
    cout << "7. Delete Course from Student\n";
    cout << "8. Update Course Marks\n";
    cout << "9. Update Course ID\n";
    cout << "10. Exit\n";
    cout << "\n*****************************************************\n";
    cout << "Enter your choice: ";
}

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 2) {
        cout << "check command line arg" << endl;
        return 1;
    }
    node* head = nullptr;
    FileHandler::loadData(head); // load data from file into linked list
    int choice, rollNo, courseId, newCourseId;
    string name;
    float cgpa, marks;
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter CGPA: ";
            cin >> cgpa;
            cout << "Enter Number of Courses: ";
            int numOfCourses;
            cin >> numOfCourses;
            courses* courseList = new courses[numOfCourses];
            for (int i = 0; i < numOfCourses; ++i) {
                cout << "Enter Course id for course " << i + 1 << ": ";
                cin >> courseId;
                cout << "Enter Marks for Course " << i + 1 << ": ";
                cin >> marks;
                courseList[i].setCourseId(courseId);
                courseList[i].setMarks(marks);
            }
            if (node_operations::addStudent(head, rollNo, name, cgpa, numOfCourses, courseList)) {
                cout << "Student added.\n";
                FileHandler::saveData(head); // Save data to file after adding student
            }
            else {
                cout << "Failed to add student.\n";
            }
            delete[] courseList;
            break;
        }
        case 2:
            cout << "Enter Roll No to delete: ";
            cin >> rollNo;
            if (node_operations::deleteStudent(head, rollNo)) {
                cout << "Student deleted.\n";
                FileHandler::saveData(head); // Save data to file after deletion
            }
            else {
                cout << "Student not found.\n";
            }
            break;
        case 3:
            cout << "Enter Roll No to find: ";
            cin >> rollNo;
            if (node* student = node_operations::findStudent(head, rollNo)) {
                cout << "Found: " << student->getName() << "\n";
            }
            else {
                cout << "Not found.\n";
            }
            break;
        case 4:
            node_operations::displayStudents(head);
            break;
        case 5:
            cout << "Enter Roll No to modify CGPA: ";
            cin >> rollNo;
            cout << "Enter new CGPA: ";
            cin >> cgpa;
            if (node_operations::modifyStudentCGPA(head, rollNo, cgpa) && cgpa <=10.0f && cgpa >=0.0f) {
                cout << "CGPA updated.\n";
                FileHandler::saveData(head); // Save data to file afte modification
            }
            else {
                cout << "Student not found.\n";
            }
            break;
        case 6:
            cout << "Enter Roll No to add course: ";
            cin >> rollNo;
            cout << "Enter Course ID: ";
            cin >> courseId;
            cout << "Enter Marks: ";
            cin >> marks;
            if (node_operations::addCourse(head, rollNo, courseId, marks)) {
                cout << "Course added.\n";
                FileHandler::saveData(head); // Save data to file after adding course
            }
            else {
                cout << "Failed to add course.\n";
            }
            break;
        case 7:
            cout << "Enter Roll No to delete course: ";
            cin >> rollNo;
            cout << "Enter Course ID to delete: ";
            cin >> courseId;
            if (node_operations::deleteCourse(head, rollNo, courseId)) {
                cout << "Course deleted.\n";
                FileHandler::saveData(head); // Save data to file after deleting course
            }
            else {
                cout << "Course not found.\n";
            }
            break;
        case 8:
            cout << "Enter Roll No to update course marks: ";
            cin >> rollNo;
            cout << "Enter Course ID: ";
            cin >> courseId;
            cout << "Enter new marks: ";
            cin >> marks;
            if (node_operations::updateCourseMarks(head, rollNo, courseId, marks)) {
                cout << "Marks updated.\n";
                FileHandler::saveData(head); // Save data to file after updating marks
            }
            else {
                cout << "Failed to update marks.\n";
            }
            break;
        case 9:
            cout << "Enter Roll No to update course ID: ";
            cin >> rollNo;
            cout << "Enter current Course ID: ";
            cin >> courseId;
            cout << "Enter new Course ID: ";
            cin >> newCourseId;
            if (node_operations::updateCourseId(head, rollNo, courseId, newCourseId)) {
                cout << "Course ID updated.\n";
                FileHandler::saveData(head); // Save data to file after updating course ID
            }
            else {
                cout << "Failed to update course ID.\n";
            }
            break;
        case 10:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

#include <iostream>
#include <fstream>
#include "../Headers/filehandler.h"
#include "../Headers/node_operations.h"
#include "../Headers/node.h"
using namespace std;

void FileHandler::loadData(node*& head) {
    ifstream file("../database/students.txt");
    if (!file.is_open()) {
        cout << "error: opening file.\n";
        return;
    }
    int rollNo, numOfCourses, courseId;
    float cgpa, marks;
    string name;

    while (file >> rollNo >> name >> cgpa >> numOfCourses) {
        courses* courseList = new courses[numOfCourses];
        for (int i = 0; i < numOfCourses; i++) {
            file >> courseId >> marks;
            courseList[i].setCourseId(courseId);
            courseList[i].setMarks(marks);
        }
        node_operations::addStudent(head, rollNo, name, cgpa, numOfCourses, courseList);
        delete[] courseList;
    }
    file.close();
}

void FileHandler::saveData(node* head) {
    ofstream file("../database/students.txt", ios::trunc);  // Open file in truncate mode to overwrite
    if (!file.is_open()) {
        cout << "Error opening file for saving data.\n";
        return;
    }
    node* current = head;
    while (current) {
        file << current->getRollNo() << " " << current->getName() << " " << current->getCgpa() << " " << current->getNumOfCourses() << "\n";
        for (int i = 0; i < current->getNumOfCourses(); i++) {
            file << current->getCourse(i).getCourseId() << " " << current->getCourse(i).getMarks() << "\n";
        }
        current = current->getNext();
    }
    file.close();
}

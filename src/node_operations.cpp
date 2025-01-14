#include "../Headers/node_operations.h"
#include <iostream>

node* node_operations::findStudent(node*& head, int rollNo) {
    node* temp = head;
    while (temp != nullptr) {
        if (temp->getRollNo() == rollNo) {
            return temp;
        }
        temp = temp->getNext();
    }
    return nullptr;
}

bool node_operations::addStudent(node*& head, int rollNo, std::string name, float cgpa, int numOfCourses, courses* course) {
    node* newStudent = new node(rollNo, name, cgpa, numOfCourses, course);
    if (!head || head->getRollNo() > rollNo) {
        newStudent->setNext(head);
        if (head) {
            head->setPrev(newStudent);
        }
        head = newStudent;
        return true;
    }
    node* temp = head;
    while (temp->getNext() && temp->getNext()->getRollNo() < rollNo) {
        temp = temp->getNext();
    }
	/*if (temp->getNext()->getRollNo() == rollNo && temp->getNext()) {
		return false;
	}*/
    newStudent->setNext(temp->getNext());
    if (temp->getNext()) {
        temp->getNext()->setPrev(newStudent);
    }
    temp->setNext(newStudent);
    newStudent->setPrev(temp);
    return true;
}

bool node_operations::deleteStudent(node*& head, int rollNo) {
    node* temp = findStudent(head, rollNo);
    if (!temp) {
        return false;
    }
    if (temp->getPrev()) {
        temp->getPrev()->setNext(temp->getNext());
    }
    else {
        head = temp->getNext();
    }
    if (temp->getNext()) {
        temp->getNext()->setPrev(temp->getPrev());
    }
    delete temp;
    return true;
}

bool node_operations::modifyStudentCGPA(node*& head, int rollNo, float cgpa) {
    node* temp = findStudent(head, rollNo);
    if (!temp) {
        return false;
    }
    temp->setCgpa(cgpa);
    return true;
}

bool node_operations::modifyStudentCourses(node*& head, int numOfCourses, int rollNo) {
    node* temp = findStudent(head, rollNo);
    if (!temp) {
        return false;
    }
    temp->setNumOfCourses(numOfCourses);
    return true;
}

bool node_operations::addCourse(node*& head, int rollNo, int cId, float mks) {
    node* studentNode = findStudent(head, rollNo);
    if (!studentNode) {
        return false;
    }

    int oldCount = studentNode->getNumOfCourses();
    courses* oldList = studentNode->getCourse();

    courses* newList = new courses[oldCount + 1];
    for (int i = 0; i < oldCount; i++) {
        newList[i] = oldList[i];
    }

    newList[oldCount].setCourseId(cId);
    newList[oldCount].setMarks(mks);

    studentNode->setNumOfCourses(oldCount + 1);

    delete[] oldList;

    studentNode->course = newList;  // Directly assign the new course list

    return true;
}

bool node_operations::updateCourseMarks(node*& head, int rollNo, int courseId, float newMarks) {
    node* temp = findStudent(head, rollNo);
    if (!temp) {
        return false;
    }
    courses* course = temp->getCourse();
    for (int i = 0; i < temp->getNumOfCourses(); i++) {
        if (course[i].getCourseId() == courseId) {
            course[i].setMarks(newMarks);
            return true;
        }
    }
    return false;
}

bool node_operations::updateCourseId(node*& head, int rollNo, int courseId, int newCourseId) {
    node* temp = findStudent(head, rollNo);
    if (!temp) {
        return false;
    }
    courses* course = temp->getCourse();
    for (int i = 0; i < temp->getNumOfCourses(); i++) {
        if (course[i].getCourseId() == courseId) {
            course[i].setCourseId(newCourseId);
            return true;
        }
    }
    return false;
}

bool node_operations::deleteCourse(node*& head, int rollNo, int courseId) {
    node* studentNode = findStudent(head, rollNo);
    if (!studentNode) {
        std::cerr << "Student not found." << std::endl;
        return false;
    }

    courses* currentCourses = studentNode->getCourse();
    int totalCourses = studentNode->getNumOfCourses();

    int courseIndex = -1;
    for (int i = 0; i < totalCourses; i++) {
        if (currentCourses[i].getCourseId() == courseId) {
            courseIndex = i;
            break;
        }
    }

    if (courseIndex == -1) {
        std::cerr << "Course not found." << std::endl;
        return false;
    }

    for (int i = courseIndex; i < totalCourses - 1; i++) {
        currentCourses[i] = currentCourses[i + 1];
    }

    studentNode->setNumOfCourses(totalCourses - 1);

    return true;
}

void node_operations::displayStudents(node* head) {
    node* temp = head;
    while (temp) {
        std::cout << "Roll No: " << temp->getRollNo() << std::endl;
        std::cout << "Name: " << temp->getName() << std::endl;
        std::cout << "CGPA: " << temp->getCgpa() << std::endl;
        std::cout << "Number of Courses: " << temp->getNumOfCourses() << std::endl;
        courses* course = temp->getCourse();
        std::cout << "--------------------------\n";
        for (int i = 0; i < temp->getNumOfCourses(); i++) {
            std::cout << "Course ID: " << course[i].getCourseId() << std::endl;
            std::cout << "Marks: " << course[i].getMarks() << std::endl;
            std::cout << "--------------------------\n";
        }
        std::cout << "--------------------------\n";
        temp = temp->getNext();
    }
}

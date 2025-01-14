#ifndef NODE_OPERATIONS_H
#define NODE_OPERATIONS_H
#include "node.h"
#include <string>
class node_operations {
private:
	static node* firstStudent(node* head, int rollNo);
public:
	static bool addStudent(node*& head, int rollNo, std::string name, float cgpa, int numOfCourses, courses* course);
	static bool deleteStudent(node*& head, int rollNo);
	static node* findStudent(node*& head, int rollNo);
	static void displayStudents(node* head);
	static bool modifyStudentCGPA(node*& head, int rollNo, float cgpa);
	static bool modifyStudentCourses(node*& head, int numOfCourses, int rollNo);
	static bool addCourse(node*& head, int rollNo, int courseId, float marks);
	static bool deleteCourse(node*& head, int rollNo, int courseId);
	static bool updateCourseMarks(node*& head, int rollNo, int courseId, float newMarks);
	static bool updateCourseId(node*& head, int rollNo, int courseId, int newCourseId);
};
#endif
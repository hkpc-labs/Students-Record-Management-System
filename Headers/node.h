#ifndef NODE_H
#define NODE_H
#include "courseinfo.h"
#include <string>
class node {
private:
	int rollNo;
	std::string name;
	
	node* next;
	node* prev;
	float cgpa;
	int numOfCourses;
public:
	courses* course;
	courses getCourse(int index);
	node(int rollNo, std::string name, float cgpa, int numOfCourses, courses* course);
	int getRollNo();
	int getNumOfCourses();
	std::string getName();
	float getCgpa();
	void setRollNo(int newRollNo);
	void setName(std::string newName);
	void setCgpa(float newCgpa);
	void addCourse(int courseId, float marks);
	void deleteCourse(int courseId);
	void updateCourse(int courseId, float newMarks);
	void displayCourses();
	node* getNext();
	node* getPrev();
	courses* getCourse();
	void setNext(node* newNext);
	void setPrev(node* newPrev);
	void setNumOfCourses(int newNumOfCourses);
};
#endif
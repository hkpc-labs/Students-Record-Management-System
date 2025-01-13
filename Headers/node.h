// node.h
#ifndef NODE_H
#define NODE_H

#include "courseinfo.h"
#include <string>

class Node {
private:
    int rollNo;           // Primary key, immutable
    std::string name;     // Primary key, immutable
    float cgpa;           // Mutable
    int numSubjects;      // Mutable
    CourseInfo* courses;  // Array of CourseInfo objects
    Node* previous;       // Pointer to previous node
    Node* next;          // Pointer to next node

public:
    // Constructor
    Node(int rollNo, const std::string& name, float cgpa, int numSubjects, CourseInfo* courses);
    
 
    
    // Getters
    int getRollNo() ;
    std::string getName() ;
    float getCGPA() ;
    CourseInfo* getCourses() ;
    int getNumSubjects() ;
    Node* getPrevious() ;
    Node* getNext() ;
    
    // Setters
    void setCGPA(float newCGPA);
    void setNumSubjects(int newNumSubjects);
    void setCourseId(int index, int newCourseId);
    void setPrevious(Node* prev);
    void setNext(Node* nxt);
};


#endif

// nodeoperations.h
#ifndef NODEOPERATIONS_H
#define NODEOPERATIONS_H

#include "node.h"

class NodeOperations {
private:
    static Node* findStudent(Node* head, int rollNo);

public:    
    // Student Operations
    static bool insertStudent(Node*& head, int rollNo, const std::string& name, 
                            float cgpa, int numSubjects, CourseInfo* courses);
    static bool deleteStudent(Node*& head, int rollNo);
    static bool modifyStudentCGPA(Node* head, int rollNo, float newCGPA);
    static bool modifyStudentSubjects(Node* head, int rollNo, int newNumSubjects);
    
    // Course Operations
    static bool addCourse(Node* head, int rollNo, int courseId, float marks);
    static bool modifyCourse(Node* head, int rollNo, int courseId, float newMarks);
    static bool modifyCourseId(Node* head, int rollNo, int oldCourseId, int newCourseId);
    static bool deleteCourse(Node* head, int rollNo, int courseId);
    
    // Display Function
    static void displayAll(Node* head);
};

#endif

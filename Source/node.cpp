// node.cpp
#include "node.h"
#include <algorithm>

/*
* Constructor for Node class
*
* Creates a new Node object representing a student record in the linked list.
* This constructor should perform a deep copy of the courses array to ensure
* each node maintains its own independent copy of course information.
*
* Parameters:
* - rollNo: Student's unique roll number identifier
* - name: Student's name
* - cgpa: Student's current CGPA
* - numSubjects: Number of courses/subjects the student is enrolled in
* - courses: Array of CourseInfo objects containing course details
*
* Important:
* - Must allocate new memory for courses array
* - Must perform deep copy of each CourseInfo object
* - Should properly initialize all pointer members (previous, next)
*
* Example:
* CourseInfo courses[2] = {CourseInfo(101, 85.5), CourseInfo(102, 90.0)};
* Node* student = new Node(1001, "John Doe", 3.8, 2, courses);
*/
Node::Node(int rollNo, const std::string& name, float cgpa, int numSubjects, CourseInfo* courses) {
    // TODO: Initialize all member variables
    // TODO: Perform deep copy of courses array
}

/*
* Retrieves student's roll number
*
* Returns:
* - Integer value of student's roll number (primary key)
*/
int Node::getRollNo() {
    // TODO: Return roll number
}

/*
* Retrieves student's name
*
* Returns:
* - String containing student's name
*/
std::string Node::getName() {
    // TODO: Return name
}

/*
* Retrieves student's CGPA
*
* Returns:
* - Float value representing student's current CGPA
*/
float Node::getCGPA() {
    // TODO: Return CGPA
}

/*
* Retrieves array of course information
*
* Returns:
* - Pointer to array of CourseInfo objects
*
* Note: Be careful with the returned pointer as it gives direct
* access to private member data
*/
CourseInfo* Node::getCourses() {
    // TODO: Return courses array pointer
}

/*
* Retrieves number of subjects
*
* Returns:
* - Integer representing the number of subjects student is enrolled in
*/
int Node::getNumSubjects() {
    // TODO: Return number of subjects
}

/*
* Retrieves pointer to previous node
*
* Returns:
* - Pointer to previous Node in the linked list
*/
Node* Node::getPrevious() {
    // TODO: Return previous node pointer
}

/*
* Retrieves pointer to next node
*
* Returns:
* - Pointer to next Node in the linked list
*/
Node* Node::getNext() {
    // TODO: Return next node pointer
}

/*
* Updates student's CGPA
*
* Parameters:
* - newCGPA: New CGPA value to be set
*
* Note: Consider adding validation for CGPA range if required
*/
void Node::setCGPA(float newCGPA) {
    // TODO: Update CGPA value
}

/*
* Updates number of subjects and resizes courses array
*
* This function should:
* 1. Create new array of size newNumSubjects
* 2. Copy existing course data to new array
* 3. Delete old array
* 4. Update member variables
*
* Parameters:
* - newNumSubjects: New number of subjects
*
* Important:
* - Must handle both increasing and decreasing number of subjects
* - Must preserve existing course data
* - Must properly manage memory (no leaks)
* - Use std::min to determine how many courses to copy
*/
void Node::setNumSubjects(int newNumSubjects) {
    // TODO: Implement resizing of courses array
}

/*
* Updates course ID at specified index
*
* Parameters:
* - index: Index in courses array to update
* - newCourseId: New course ID to set
*
* Important:
* - Verify index is within valid range
* - Only update if index is valid
*/
void Node::setCourseId(int index, int newCourseId) {
    // TODO: Update course ID if index is valid
}

/*
* Sets pointer to previous node
* No need to implement
* Parameters:
* - prev: Pointer to previous Node in linked list
*/
void Node::setPrevious(Node* prev) {
    previous = prev;
}

/*
* Sets pointer to next node
* No need to implement
* Parameters:
* - nxt: Pointer to next Node in linked list
*/
void Node::setNext(Node* nxt) {
    next = nxt; 
}

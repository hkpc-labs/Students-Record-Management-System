#include "courseinfo.h"

/*
* Constructor for CourseInfo class
* 
* This constructor initializes a new CourseInfo object with the given course ID and marks.
* If no parameters are provided, it initializes with default values.
*
* Parameters:
* - courseId: Integer representing the unique identifier for the course
* - marks: Float value representing the student's marks in the course
*          Should be in the range 0.0 to 100.0
*
* Example usage:
* CourseInfo course1(101, 85.5);  // Creates course with ID 101 and marks 85.5
* CourseInfo course2;             // Creates course with default values (0, 0.0)
*/
CourseInfo::CourseInfo(int courseId, float marks) {
    // TODO: Initialize the course ID and marks
}

/*
* Retrieves the course ID
*
* This function should return the stored course ID value.
* The course ID is a unique identifier for each course.
*
* Returns:
* - Integer value representing the course ID
*
* Note: This is a getter method and should not modify any class members
*/
int CourseInfo::getCourseId() {
    // TODO: Return the course ID
}

/*
* Retrieves the marks obtained in the course
*
* This function should return the stored marks value.
* Marks represent the student's performance in the course.
*
* Returns:
* - Float value representing the marks (typically between 0.0 and 100.0)
*
* Note: This is a getter method and should not modify any class members
*/
float CourseInfo::getMarks() {
    // TODO: Return the marks
}

/*
* Updates the course ID
*
* This function should update the stored course ID with the new value.
* Use this when you need to change the course identifier.
*
* Parameters:
* - newCourseId: Integer value representing the new course ID to be set
*
* Note: Ensure proper validation if needed (e.g., checking for positive values)
*/
void CourseInfo::setCourseId(int newCourseId) {
    // TODO: Set the new course ID
}

/*
* Updates the marks for the course
*
* This function should update the stored marks with the new value.
* Use this when you need to modify a student's marks in the course.
*
* Parameters:
* - newMarks: Float value representing the new marks to be set
*            Should typically be between 0.0 and 100.0
*
* Note: Consider adding validation for the marks range if required
*/
void CourseInfo::setMarks(float newMarks) {
    // TODO: Set the new marks
}

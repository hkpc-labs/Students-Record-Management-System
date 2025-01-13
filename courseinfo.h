#ifndef COURSEINFO_H
#define COURSEINFO_H

class CourseInfo {
private:
    int courseId;      // Mutable
    float marks;       // Mutable

public:
    // Constructor
    CourseInfo(int courseId = 0, float marks = 0.0);
    
    // Getters
    int getCourseId() ;
    float getMarks();
    
    // Setters
    void setCourseId(int newCourseId);
    void setMarks(float newMarks);
    
};

#endif

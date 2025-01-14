# Student Records Management System using double linked list
 In this programming assignment, you will develop a student records management system using doubly
 linked lists. The system will store and manage student data including roll numbers, names, CGPAs, and
 their enrolled courses with respective marks. You are required to implement this system using C++ with
 a focus on modular programming concepts. Your program must handle a series of operations through
 f
 ile input, such as adding or removing students, updating their academic records, and managing course
 enrollments. Each operation should maintain the structural integrity of the doubly linked list while
 allowing efficient data manipulation. The implementation must be divided into four distinct modules to
 ensure code organization and maintainability. Each module will handle specific aspects of the system’s
 functionality as detailed in the following sections.
 ## Module Specifications
 ###  Module 1.1
  CourseInfo Implementation (courseinfo.cpp, courseinfo.h)
 Implement the basic structure for storing course information
  ```cpp
     class CourseInfo {
         private:
             int courseId;
             // Mutable
             float marks;
             // Mutable
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
```
### MOdule 1.2
 Node Implementation (node.cpp, node.h)
 Implement the basic structure for Node information
```cpp
  #include "courseinfo.h"
  #include <string>
 class Node {
 private:
     int rollNo;
     std::string name;
     float cgpa;
     int numSubjects;
     // immutable
     // immutable
     // Mutable
     // Mutable
     CourseInfo* courses; // Array of CourseInfo objects
     Node* previous;
     // Pointer to previous node
     Node* next;
     // Pointer to next node
 public:
     // Constructor
     Node(int rollNo, const std::string& name, float cgpa, int numSubjects,
     CourseInfo* courses);
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
```
### Module 2 
 Node Operations (node operations.cpp, node operations.h)
 Implement all operations on the linked list:
 • Insert new student node
 • Delete existing student node
 • Modify student CGPA
 • Add new course to student record
 • Modify course marks
 • Delete course from student record
 • Search operation
 Essentialoperationsformanagingstudentrecords
```cpp
 #include "node.h"
 3
 4 class NodeOperations {
 5 private:
     6 static Node* findStudent(Node* head, int rollNo);
     7
 8 public:
     9 // Student Operations
     10 static bool insertStudent(Node*& head, int rollNo, const std::string& name,
     11 float cgpa, int numSubjects, CourseInfo* courses);
     12 static bool deleteStudent(Node*& head, int rollNo);
     13 static bool modifyStudentCGPA(Node* head, int rollNo, float newCGPA);
     14 static bool modifyStudentSubjects(Node* head, int rollNo, int
     newNumSubjects);
     15
     16 // Course Operations
     17 static bool addCourse(Node* head, int rollNo, int courseId, float marks);
     18 static bool modifyCourse(Node* head, int rollNo, int courseId, float
     newMarks);
     19 static bool modifyCourseId(Node* head, int rollNo, int oldCourseId, int
     newCourseId);
     20 static bool deleteCourse(Node* head, int rollNo, int courseId);
     21
     22 // Display Function
     23 static void displayAll(Node* head);
 24 };
```
### Module 3
FileHandler(filehandler.cpp,filehandler.h)
 Implementfilereadingandcommandprocessingoperations:
 •Readinputfile
 •Parsedifferentsectionsoftheinput
 •Executeappropriateoperationsbasedoncommands
 •Handlefileformatvalidatio
```cpp
 1 #include "node_operations.h"
 2 #include <string>
 3 #include <vector>
 4
 5 class FileHandler {
 6 private:
     7 Node*& head;
     8
     9 // Helper functions for parsing data
     10 std::vector<std::string> splitAndTrim(const std::string& str);
     11 bool parseStudentData(const std::string& line, int& rollNo, std::string&
     name, float& cgpa, int& numSubjects);
     12 bool parseCourseData(const std::string& line, int& courseId, float& marks);
     13 bool parseModifyData(const std::string& line, int& id, float& value);
     14
     15 // Helper functions for each operation type
     16 void handleInitialList(const std::vector<std::string>& lines);
     17 void handleAddStudent(const std::string& line);
     18 void handleAddCourse(const std::string& line);
     19 void handleModifyStudent(const std::string& line);
     20 void handleModifyCourse(const std::string& line);

     void handleDeleteStudent(const std::string& line);
     void handleDeleteCourse(const std::string& line);
 public:
     FileHandler(Node*& head) : head(head) {}
     bool processFile(const std::string& filename);
 };
```
### Module 4
 Main Program (main.cpp
 ```cpp
 #include "filehandler.h"
 #include "node_operations.h"
 #include <iostream>
 #include <string>
 using namespace std;
 int main(int argc, char* argv[]) {
 // Check command line arguments
     if (argc != 2) {
         cout<<"check␣command␣line␣arg"<<endl;
         return 1;
     }
     // Initialize head pointer
     Node* head = nullptr;
     // Create file handler with head pointer
     FileHandler fileHandler(head);
     if (!fileHandler.processFile(argv[1])) {
         cout << "Error" << argv[1] << endl;
         return 1;
     }
     cout << "File␣processed␣successfully." << endl;
     return 0;
 }
```

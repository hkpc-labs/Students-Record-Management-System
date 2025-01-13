// filehandler.h
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "node_operations.h"
#include <string>
#include <vector>

class FileHandler {
private:
    Node*& head;

    // Helper functions for parsing data
    std::vector<std::string> splitAndTrim(const std::string& str);
    bool parseStudentData(const std::string& line, int& rollNo, std::string& name, float& cgpa, int& numSubjects);
    bool parseCourseData(const std::string& line, int& courseId, float& marks);
    bool parseModifyData(const std::string& line, int& id, float& value);

    // Helper functions for each operation type
    void handleInitialList(const std::vector<std::string>& lines);
    void handleAddStudent(const std::string& line);
    void handleAddCourse(const std::string& line);
    void handleModifyStudent(const std::string& line);
    void handleModifyCourse(const std::string& line);
    void handleDeleteStudent(const std::string& line);
    void handleDeleteCourse(const std::string& line);

public:
     FileHandler(Node*& head) : head(head) {}
    bool processFile(const std::string& filename);
};

#endif

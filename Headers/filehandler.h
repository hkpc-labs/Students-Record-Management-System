#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "node.h"

class FileHandler {
public:
    static void loadData(node*& head);
    static void saveData(node* head);
};

#endif

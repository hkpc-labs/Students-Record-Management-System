
#include "filehandler.h"
#include "node_operations.h"
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 2) {
        cout<<"check command line arg"<<endl;
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
    
    cout << "File processed successfully." << endl;
    return 0;
}

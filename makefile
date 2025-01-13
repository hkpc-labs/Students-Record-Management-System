# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g 

# Target executable
TARGET = main

# Source and Header directories
SRC_DIR = Source
HEADER_DIR = Headers
FILES_DIR = temp

# Source files
SRCS = main.cpp \
       $(SRC_DIR)/courseinfo.cpp \
       $(SRC_DIR)/filehandler.cpp \
       $(SRC_DIR)/node.cpp \
       $(SRC_DIR)/node_operations.cpp

# Object files
OBJS = $(FILES_DIR)/$(notdir $(SRCS:.cpp=.o))

# Header files
HEADERS = $(HEADER_DIR)/courseinfo.h \
          $(HEADER_DIR)/filehandler.h \
          $(HEADER_DIR)/node.h \
          $(HEADER_DIR)/node_operations.h

# Default target
all: $(TARGET)

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
$(FILES_DIR)/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile .cpp files from Source folder
$(FILES_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable with input file
run: $(TARGET)
	./$(TARGET) input.txt

# Alternative run rule that allows any input file
# Usage: make run INPUT=your_input_file.txt
run-with-file: $(TARGET)
	./$(TARGET) $(INPUT)

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all run run-with-file clean

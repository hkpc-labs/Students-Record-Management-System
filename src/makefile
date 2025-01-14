# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Target executable
TARGET = ../temp/main

# Source and Header directories
SRC_DIR = .
HEADER_DIR = ../Headers
FILES_DIR = ../temp

# Source files
SRCS = $(SRC_DIR)/main.cpp \
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
$(TARGET): $(OBJS) | $(FILES_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Rule to compile .cpp files into .o files
$(FILES_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(FILES_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to create the temp directory if it doesn't exist
$(FILES_DIR):
	mkdir -p $(FILES_DIR)

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

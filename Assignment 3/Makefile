# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -Wno-c++11-extensions

# Target executable
TARGET = main

# Source files
SRCS = main.cpp

# Header files
HEADERS = GlobalOutput.h \
		  BinarySearchTree/Node.h \
		  BinarySearchTree/BST.h \
		  BinarySearchTree/magicitems.txt \
		  BinarySearchTree/magicitems-find-in-bst.txt \
		  UndirectedGraph/Graph.h \
		  UndirectedGraph/Vertex.h \
		  UndirectedGraph/Matrix.h \
		  UndirectedGraph/AdjacencyList.h \
		  UndirectedGraph/Queue.h \
		  UndirectedGraph/graphs1.txt

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files, adding header dependencies
main.o: main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove generated files
# Uses del if on windows, uses rm on Unix-like systems (and Git Bash)
clean: 
	rm -f main $(OBJS) output.txt || del main.exe $(OBJS) output.txt
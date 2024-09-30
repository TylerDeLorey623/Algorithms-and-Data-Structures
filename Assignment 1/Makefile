# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Target executable
TARGET = main

# For deleting the target
ifeq ($(OS),Windows_NT)
	TARGET_DEL = main.exe
else
	TARGET_DEL = main.out
endif

# Source files
SRCS = main.cpp

# Header files
HEADERS = Node.h Queue.h Stack.h isPalindrome.h Sorts.h

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
# Uses del if on windows, uses rm on Unix-like systems
clean:
ifeq ($(OS),Windows_NT)
	del $(TARGET_DEL) $(OBJS)
else
	rm $(TARGET_DEL) $(OBJS)
endif
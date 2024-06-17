CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude -I/usr/include/qt5

# List your source files
SOURCES = src/file_operations.cpp src/main.cpp

# Generate object file names from source files
OBJECTS = $(SOURCES:.cpp=.o)

# Specify the output executable name
EXECUTABLE = ProFileX

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o build/$(EXECUTABLE) -lQt5Core -lQt5Widgets

# Rule for compiling each .cpp file to a .o object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build

.PHONY: all clean

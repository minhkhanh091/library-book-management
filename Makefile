TARGET = library

SRCS = library_main.cpp file_io.cpp book.cpp utils.cpp handle_menu.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
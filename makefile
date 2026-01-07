CXX = g++
CXXFLAGS = -Wall -Werror -O0 -g

SRC_DIR = src

TARGET = todoit

SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/parse/parse.cpp# $(SRC_DIR)/structures/task_container.hpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


sani: CXXFLAGS = -Wall -g -O0 -fsanitize=address -fsanitize=leak
sani: $(TARGET)_san

$(TARGET)_san: $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@


.PHONY : clean

clean:
	rm $(TARGET) $(OBJS) $(TARGET)_san *.txt

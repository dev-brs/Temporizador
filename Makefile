CXX = g++
CXXFLAGS = -std=c++11
SRCS = kronos.cpp src/mat.cpp src/colors.cpp src/timer.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = out

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

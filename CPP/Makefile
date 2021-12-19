##
# C++ for Lam's Algorithms
# Author: Lam Duong
#
# @file
# @version 0.1

CXXFLAGS = -std=c++20 -g
CXX = g++

TARGET = Algorithms
TESTS = AlgoTests
all: $(TARGET)
$(TARGET): $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp $(TARGET).hpp
tests: $(TESTS)
$(TESTS): $(TESTS).cpp
	$(CXX) $(CXXFLAGS) $(TESTS).cpp -o $(TESTS) $(TARGET).cpp
clean:
	$(RM) $(TARGET) $(TESTS)

# end

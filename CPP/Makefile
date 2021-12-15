##
# C++ for Lam's Algorithms
# Author: Lam Duong
#
# @file
# @version 0.1

CXXFLAGS = -std=c++20 -g
CC = clang++

TARGET = Algorithms
all: $ (TARGET)
$ (TARGET): $(TARGET).cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp -I $(TARGET).hpp
clean:
	$(RM) $(TARGET)

# end

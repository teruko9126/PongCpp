CC = clang++
VERSION = -std=c++17
TARGET = Pong

SRCS = main.cpp
SRCS += pong.cpp
SRCS += bar.cpp

LIBS = -lSDL2

$(TARGET): $(SRCS) 
	$(CC) $(VERSION) -o $@ $(SRCS) $(LIBS) 
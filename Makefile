CC = clang++

TARGET = Pong

SRCS = main.cpp
SRCS += pong.cpp

LIBS = -lSDL2

$(TARGET): $(SRCS) 
	$(CC) -o $@ $(SRCS) $(LIBS) 
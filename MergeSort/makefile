CC = g++
CFLAGS = -Wall -std=c++1z
DEPS = mergeSort_Thread.h benchMark.h
OBJ = mergeSort_Thread.o benchMark.o main.o -lpthread
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^


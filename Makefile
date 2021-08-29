CC=g++
CFLAGS=-I.
SRC_DIR = src
HEADER_DIR = headers
OBJ = $(wildcard $(SRC_DIR)/*.cpp)
DEPS = $(wildcard $(HEADER_DIR)/*.h)
#DEPS = input.h output.h arithmetics.h unittest.h
#OBJ = input.o output.o arithmetics.o unittest.o quadratic.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

quadratic: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean :
	

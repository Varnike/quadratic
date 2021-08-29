CC=g++
CFLAGS=-I.
DEPS = input.h output.h arithmetics.h unittest.h
OBJ = input.o output.o arithmetics.o unittest.o quadratic.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

quadratic: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
clean :
	rm $(OBJ)

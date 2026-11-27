# Makefile for the biorhythm calculator
# Usage: make        build the program
#        make run    build and run it
#        make clean  delete the generated files

CC = gcc
CFLAGS = -std=c99 -Wall -Wextra
LDLIBS = -lm

TARGET = biorhythm
OBJECTS = main.o biorhythm.o reports.o globaldata.o
HEADERS = biorhythm.h reports.h globaldata.h

all: $(TARGET)

# Link: join the object files into the executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDLIBS)

# Compile: each .c file becomes a .o file.
# Recompiled when the .c file or any header changes
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) $(OBJECTS) $(TARGET) $(TARGET).exe

.PHONY: all run clean

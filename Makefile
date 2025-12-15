CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
SRCS = src/main.c src/student_data.c src/file_handler.c
OBJS = bin/main.o bin/student_data.o bin/file_handler.o
TARGET = bin/grading_system
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS)
bin/main.o: src/main.c include/student.h
	$(CC) $(CFLAGS) -c src/main.c -o bin/main.o
bin/student_data.o: src/student_data.c include/student.h
	$(CC) $(CFLAGS) -c src/student_data.c -o bin/student_data.o
bin/file_handler.o: src/file_handler.c include/student.h
	$(CC) $(CFLAGS) -c src/file_handler.c -o bin/file_handler.o
clean:
	@echo "--- MANUAL CLEANING REQUIRED ---"
	@echo "Please manually delete the 'bin' folder and its contents."
run: $(TARGET)
	./$(TARGET)
.PHONY: all run clean
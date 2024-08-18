# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

LDFLAGS = -lcunit

INCLUDES = -I$(SRC_DIR)/line -I$(SRC_DIR)/list

# Directories
SRC_DIR = src
TRG_DIR = exe
LINE_DIR = $(SRC_DIR)/line
LIST_DIR = $(SRC_DIR)/list
TEST_DIR = test

# Executable names
MAIN_TARGET = $(TRG_DIR)/program
TEST_TARGET = $(TRG_DIR)/test_program

# Source files
MAIN_SRCS = $(SRC_DIR)/main.c $(LINE_DIR)/line.c $(LIST_DIR)/list.c
TEST_SRCS = $(TEST_DIR)/test.c $(LINE_DIR)/line.c $(LIST_DIR)/list.c

# Object files
MAIN_OBJS = $(MAIN_SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

# Main Arguments
MAIN_ARG1 = files/input.c
MAIN_ARG2 = files/output.txt

# Default target: builds the main program
all: $(MAIN_TARGET)

# Build the main program
$(MAIN_TARGET): $(MAIN_OBJS)
	$(CC) $(CFLAGS) -o $(MAIN_TARGET) $(MAIN_OBJS)

# Build the test program
$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) $(LDFLAGS)

# Compile
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean build files
clean:
	rm -f $(MAIN_OBJS) $(TEST_OBJS)

# Run the main program
run_main: $(MAIN_TARGET)
	./$(MAIN_TARGET) ${MAIN_ARG1} $(MAIN_ARG2)
	$(MAKE) clean

# Run the test program
run_test: $(TEST_TARGET)
	./$(TEST_TARGET)
	$(MAKE) clean

# Phony targets
.PHONY: all clean run_main run_test

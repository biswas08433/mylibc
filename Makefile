########################################################################
####################### Makefile Template ##############################
########################################################################

# Do NOT change these things
SHELL := bash
.ONESHELL:
.SHELLFLAGS := -eu -o pipefail -c
.DELETE_ON_ERROR:
MAKEFLAGS += --warn-undefined-variables
########################################################################



# Makefile settings - Can be customized.
TEST_APP = test01
TEST_BUILD_DIR = ./test/build
LIBNAME = libmylibc
SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ./lib
INC_DIR = ./include

# Compiler settings - Can be customized.

CC = gcc
CFLAGS = -std=c11 -g -Werror -Wall -I$(INC_DIR)
LDFLAGS = -L./lib -lmylibc -lm

SRC = $(shell find $(SRC_DIR) -name *.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

RM = rm
MKDIR_P = mkdir -p

########################################################################
####################### Targets beginning here #########################
########################################################################

.PHONY:lib test testrun clean

testrun:
	$(TEST_BUILD_DIR)/$(TEST_APP)

test : $(TEST_APP)

lib: $(LIBNAME).a



$(TEST_APP): $(TEST_APP).o $(LIBNAME).a
	$(CC) $(CFLAGS) -o $(TEST_BUILD_DIR)/$@ $(TEST_BUILD_DIR)/$< $(LDFLAGS)

test01.o : ./test/test01.c
	$(CC) $(CFLAGS) -o $(TEST_BUILD_DIR)/$@ -c $^



# Builds the lib
$(LIBNAME).a: $(OBJ)
	$(MKDIR_P) $(LIB_DIR)
	ar -rcs $(LIB_DIR)/$@ $^

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

################### Cleaning rules ###################

clean:
	rm -r $(OBJ_DIR) $(LIB_DIR)
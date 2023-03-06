########################################################################
####################### Makefile Template ##############################
########################################################################

# Makefile settings - Can be customized.

LIBNAME = lucy
EXT = .c
SRCDIR = ./src
OBJDIR = ./obj
BUILD = ./build
INCDIR = ./include

# Compiler settings - Can be customized.

CC = gcc
CFLAGS = -std=c11 -g -Werror -Wall -I$(INCDIR)
LDFLAGS = -lm



############## Do not change anything from here downwards! #############
SRC = $(shell find $(SRCDIR) -name *$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)

RM = rm
DELOBJ = $(OBJ)
MKDIR_P = mkdir -p

########################################################################
####################### Targets beginning here #########################
########################################################################

.PHONY:all run clean fullclean


all: $(LIBNAME)


# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

################### Cleaning rules ###################
# Cleans complete project
clean:
	$(RM) -f $(DELOBJ) $(DEP) $(APPNAME)

fullclean:
	$(RM) -f $(DELOBJ) $(APPNAME)
	$(RM) -r ./obj

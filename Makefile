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

<<<<<<< HEAD
=======
# UNIX-based OS variables & settings
>>>>>>> eaac6208ebab4ac5be80b123b4bae395ca8ceafd
RM = rm
DELOBJ = $(OBJ)
MKDIR_P = mkdir -p

########################################################################
####################### Targets beginning here #########################
########################################################################

<<<<<<< HEAD
.PHONY:all run clean fullclean
=======
.PHONY:all run fullclean
>>>>>>> eaac6208ebab4ac5be80b123b4bae395ca8ceafd


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
<<<<<<< HEAD
	$(RM) -r ./obj
=======
	$(RM) -r ./obj ./dep

# Cleans only all files with the extension .d
cleandep:
	$(RM)  -f $(DEP)
>>>>>>> eaac6208ebab4ac5be80b123b4bae395ca8ceafd

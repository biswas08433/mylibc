########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = gcc
<<<<<<< HEAD
CXXFLAGS = -std=c11 -g -Werror -Wall -Isrc/include/
=======
CXXFLAGS = -std=c11 -Werror -Wall -g
>>>>>>> e94f3299efdaab3487acf84208fd67976f1febba
LDFLAGS = -lm

# Makefile settings - Can be customized.
APPNAME = main
EXT = .c
SRCDIR = ./src
OBJDIR = ./obj
#DEPDIR = ./dep

############## Do not change anything from here downwards! #############
SRC = $(shell find $(SRCDIR) -name *$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
#DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/%.d)
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
MKDIR_P = mkdir -p

########################################################################
####################### Targets beginning here #########################
########################################################################

.PHONY:all run clean fullclean cleandep cleanw cleandepw


all: $(APPNAME)

run:
	./$(APPNAME)


# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
# $(DEPDIR)/%.d: $(SRCDIR)/%$(EXT)
# 	$(MKDIR_P) $(dir $@)
# 	$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=%.o) >$@

# Includes all .h files
# -include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(MKDIR_P) $(dir $@)
	$(CC) $(CXXFLAGS) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################
# Cleans complete project
clean:
	$(RM) -f $(DELOBJ) $(DEP) $(APPNAME)

fullclean:
	$(RM) -f $(DELOBJ) $(DEP) $(APPNAME)
	$(RM) -r ./dep ./obj

# Cleans only all files with the extension .d
cleandep:
	$(RM)  -f $(DEP)
# Compiler
CC = g++

# Flags
CFLAGS = -Wall -c -Ilib/UnitTest++/src/
LFLAGS = -lglfw
TESTLFLAGS = -Llib/UnitTest++/ -lUnitTest++

# directories
SRCDIR = src/
RESOURCEDIR = res/
BUILDDIR   = build/
OBJDIR     = obj/
PRODUCTDIR = product/

# file lists
SOURCES     = $(notdir $(wildcard src/*.cpp))
HEADERS     = $(notdir $(wildcard src/*.h))
OBJECTS     = $(filter-out Test%, $(SOURCES:.cpp=.o))
TESTOBJECTS = $(filter-out main.o,$(SOURCES:.cpp=.o))

# Final products
PRODUCT = derelict
TESTPRODUCT = test

# Libraries
TESTLIB = lib/UnitTest++/libUnitTest++.a

# Mac specific options

# Extra flags
MACCFLAGS =
MACLFLAGS = -framework OpenGL -framework Cocoa

# Directories
MACBUILDDIR   = $(BUILDDIR)mac/
MACOBJDIR     = $(MACBUILDDIR)$(OBJDIR)
MACPRODUCTDIR = $(MACBUILDDIR)$(PRODUCTDIR)

# File lists
MACOBJECTS     = $(addprefix $(MACOBJDIR), $(OBJECTS))
MACTESTOBJECTS = $(addprefix $(MACOBJDIR), $(TESTOBJECTS))

# Final products
MACPRODUCT = $(MACOBJDIR)$(PRODUCT)
MACAPP     = $(MACPRODUCTDIR)$(PRODUCT).app
MACTEST    = $(MACOBJDIR)$(TESTPRODUCT)

# Colors for output
NO_COLOR=\x1b[0m
CYAN_COLOR=\x1b[1;36;01m
GREEN_COLOR=\x1b[32;01m
RED_COLOR=\x1b[31;01m


.PHONY: mac
mac: $(MACAPP)/.build $(MACTEST)

.PHONY: clean
clean:
	@echo "$(GREEN_COLOR)Cleaning$(NO_COLOR) build/"
	@-rm -rf $(BUILDDIR)

.PHONY: clean-all
clean-all: clean
	@echo "$(GREEN_COLOR)Cleaning$(NO_COLOR) UnitTest++"
	@cd $(dir $(TESTLIB)); make clean

.PHONY: mac-res
mac-res: $(MACAPP)/.build
	@echo "$(GREEN_COLOR)Copying$(NO_COLOR) resources"
	@cp -R $(RESOURCEDIR)Resources/* $(MACAPP)/Contents/Resources/ 

$(MACAPP)/.build: $(MACPRODUCT) | $(MACPRODUCTDIR)
	@echo "$(GREEN_COLOR)Building$(NO_COLOR) $(PRODUCT).app"
	./lib/makeapp $(PRODUCT) $(MACAPP) $(MACPRODUCT) $(RESOURCEDIR)Info.plist
	@touch $(MACAPP)/.build
	@cp -R $(RESOURCEDIR)Resources/* $(MACAPP)/Contents/Resources/ 

$(MACTEST): $(MACTESTOBJECTS) $(TESTLIB) | $(MACOBJDIR)
	@echo "$(GREEN_COLOR)Building$(NO_COLOR) tests"
	@$(CC) $(LFLAGS) $(MACLFLAGS) $(TESTLFLAGS) $^ -o $@
	@echo "$(RED_COLOR)Running$(NO_COLOR) tests"
	@./$(MACTEST)

$(MACPRODUCT): $(MACOBJECTS) | $(MACOBJDIR)
	@echo "$(GREEN_COLOR)Building$(NO_COLOR) $(PRODUCT)"
	@$(CC) $(LFLAGS) $(MACLFLAGS) $^ -o $@

$(MACOBJDIR)%.o: $(addprefix $(SRCDIR), %.cpp) $(addprefix $(SRCDIR), $(HEADERS)) | $(MACOBJDIR)
	@echo "$(CYAN_COLOR)Compiling$(NO_COLOR) $(notdir $@)"
	@$(CC) $(CFLAGS) $(MACCFLAGS) $< -o $@

$(TESTLIB):
	@echo "$(GREEN_COLOR)Building$(NO_COLOR) libUnitTest++"
	@cd $(dir $@); make

$(MACOBJDIR) $(MACPRODUCTDIR):
	@mkdir -p $@

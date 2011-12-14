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
SOURCES       = Cam.cpp\
	        DisplayFuncs.cpp\
	        Floor.cpp\
	        Key.cpp\
	        Player.cpp\
	        Vector.cpp\
	        Wall.cpp\
	        World.cpp\
	        main.cpp\
		Editmain.cpp\
		Editor.cpp\
	        Testmain.cpp\
	        TestCam.cpp\
	        TestFloor.cpp\
	        TestKey.cpp\
	        TestPlayer.cpp\
	        TestWall.cpp\
	        TestWorld.cpp
HEADERS       = Cam.h\
	        DisplayFuncs.h\
	        Floor.h\
	        Key.h\
	        Player.h\
	        Vector.h\
	        Wall.h\
	        World.h
COMMONOBJECTS = Cam.o\
		DisplayFuncs.o\
		Floor.o\
		Key.o\
		Player.o\
		Vector.o\
		Wall.o\
		World.o
MAINOBJECTS   = main.o
EDITOBJECTS   = Editmain.o\
		Editor.o
TESTOBJECTS   = Testmain.o\
		TestCam.o\
		TestFloor.o\
		TestKey.o\
		TestPlayer.o\
		TestWall.o\
		TestWorld.o

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
MACMAINOBJECTS = $(addprefix $(MACOBJDIR), $(MAINOBJECTS) $(COMMONOBJECTS))
MACTESTOBJECTS = $(addprefix $(MACOBJDIR), $(TESTOBJECTS) $(COMMONOBJECTS))
MACEDITOBJECTS = $(addprefix $(MACOBJDIR), $(EDITOBJECTS) $(COMMONOBJECTS))

# Final products
MACPRODUCT     = $(MACOBJDIR)$(PRODUCT)
MACAPP         = $(MACPRODUCTDIR)$(PRODUCT).app
MACEDITPRODUCT = $(MACOBJDIR)editor
MACEDITAPP     = $(MACPRODUCTDIR)editor.app
MACTEST        = $(MACOBJDIR)$(TESTPRODUCT)

# Colors for output
NO_COLOR=\x1b[0m
CYAN_COLOR=\x1b[1;36;01m
GREEN_COLOR=\x1b[32;01m
RED_COLOR=\x1b[31;01m


.PHONY: mac
mac: $(MACAPP)/.build $(MACEDITAPP)/.build $(MACTEST)

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
	@./lib/makeapp $(PRODUCT) $(MACAPP) $(MACPRODUCT) $(RESOURCEDIR)Info.plist
	@touch $(MACAPP)/.build
	@cp -R $(RESOURCEDIR)Resources/* $(MACAPP)/Contents/Resources/

$(MACEDITAPP)/.build: $(MACEDITPRODUCT) | $(MACPRODUCTDIR)
	@echo "$(GREEN_COLOR)Building$(NO_COLOR) editor.app"
	@./lib/makeapp editor $(MACEDITAPP) $(MACEDITPRODUCT) $(RESOURCEDIR)Info.plist
	@touch $(MACEDITAPP)/.build
	@cp -R $(RESOURCEDIR)Resources/* $(MACAPP)/Contents/Resources/

$(MACTEST): $(MACTESTOBJECTS) $(TESTLIB) | $(MACOBJDIR)
	@echo "$(GREEN_COLOR)Building$(NO_COLOR) tests"
	@$(CC) $(LFLAGS) $(MACLFLAGS) $(TESTLFLAGS) $^ -o $@
	@echo "$(RED_COLOR)Running$(NO_COLOR) tests"
	@./$(MACTEST)

$(MACPRODUCT): $(MACMAINOBJECTS) | $(MACOBJDIR)
	@echo "$(GREEN_COLOR)Building$(NO_COLOR) $(PRODUCT)"
	@$(CC) $(LFLAGS) $(MACLFLAGS) $^ -o $@

$(MACEDITPRODUCT): $(MACEDITOBJECTS) | $(MACOBJDIR)
	@echo "$(GREEN_COLOR)Building$(NO_COLOR) editor"
	@$(CC) $(LFLAGS) $(MACLFLAGS) $^ -o $@

$(MACOBJDIR)%.o: $(addprefix $(SRCDIR), %.cpp) $(addprefix $(SRCDIR), $(HEADERS)) | $(MACOBJDIR)
	@echo "$(CYAN_COLOR)Compiling$(NO_COLOR) $(notdir $@)"
	@$(CC) $(CFLAGS) $(MACCFLAGS) $< -o $@

$(TESTLIB):
	@echo "$(GREEN_COLOR)Building$(NO_COLOR) libUnitTest++"
	@cd $(dir $@); make

$(MACOBJDIR) $(MACPRODUCTDIR):
	@mkdir -p $@

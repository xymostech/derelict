CC = g++

CFLAGS = -Wall -c
LFLAGS = -lglfw


PRODUCT = derelict


SRCDIR = src/
RESOURCEDIR = res/

BUILDDIR   = build/

OBJDIR     = obj/
PRODUCTDIR = product/


SOURCES = $(notdir $(wildcard src/*.cpp))
HEADERS = $(notdir $(wildcard src/*.h))
OBJECTS = $(SOURCES:.cpp=.o)


MACCFLAGS = 
MACLFLAGS = -framework OpenGL -framework Cocoa

MACBUILDDIR   = $(BUILDDIR)mac/

MACOBJDIR     = $(MACBUILDDIR)$(OBJDIR)
MACPRODUCTDIR = $(MACBUILDDIR)$(PRODUCTDIR)

MACPRODUCT = $(MACOBJDIR)$(PRODUCT)
MACAPP     = $(MACPRODUCTDIR)$(PRODUCT).app


MACOBJECTS = $(addprefix $(MACOBJDIR), $(OBJECTS))

.PHONY: all
all: macprod

.PHONY: clean
clean:
	@-rm -rf $(BUILDDIR)

.PHONY: macprod
macprod: $(MACAPP)

$(MACAPP): $(MACPRODUCT) | $(MACPRODUCTDIR)
	mkdir -p $(MACAPP)
	mkdir -p $(MACAPP)/Contents
	sed s/@PROD/$(PRODUCT)/ <$(RESOURCEDIR)Info.plist >$(MACAPP)/Contents/Info.plist
	mkdir -p $(MACAPP)/Contents/MacOS
	cp $(MACPRODUCT) $(MACAPP)/Contents/MacOS/
	mkdir -p $(MACAPP)/Contents/Resources
	mkdir -p $(MACAPP)/Contents/Resources/English.lproj
	cp $(RESOURCEDIR)MainMenu.xib $(MACAPP)/Contents/Resources/English.lproj/

$(MACPRODUCT): $(MACOBJECTS) | $(MACOBJDIR)
	$(CC) $(LFLAGS) $(MACLFLAGS) $^ -o $@

$(MACOBJDIR)%.o: $(addprefix $(SRCDIR), %.cpp) $(addprefix $(SRCDIR), $(HEADERS)) | $(MACOBJDIR)
	$(CC) $(CFLAGS) $(MACCFLAGS) $< -o $@

$(MACOBJDIR) $(MACPRODUCTDIR):
	mkdir -p $@

# Declaration of variables
CC = gcc-4.8
CXX = g++-4.8
${CC := gcc-4.8}
${CXX := g++-4.8}
CXX_FLAGS = -Wall -std=c++0x

MKDIR = mkdir -p
MV = mv
OUTDIR = ../bin
SFMLLIB = ../SFML/SFML-2.4.2-Linux64/lib/

#Headers and Includes
LIB=-L../SFML/SFML-2.4.2-Linux64/lib
INC=-I../SFML/SFML-2.4.2-Linux64/include -I../include
DLIBS=-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
 
# File names
EXEC = flappybird
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
 
# Main target
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC) $(LIB) $(DLIBS)
 
# To obtain object files
%.o: %.cpp
	$(CXX) $(INC) -c $(CXX_FLAGS) $< -o $@
 
install:
	$(MKDIR) ../bin
	install -m 755 $(EXEC) $(OUTDIR)
	cp -r Resources/ $(OUTDIR)/Resources/
	install -m 755 $(SFMLLIB)libsfml-audio.* $(OUTDIR)
	install -m 755 $(SFMLLIB)libsfml-graphics.* $(OUTDIR)
	install -m 755 $(SFMLLIB)libsfml-system.* $(OUTDIR)
	install -m 755 $(SFMLLIB)libsfml-window.* $(OUTDIR)

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
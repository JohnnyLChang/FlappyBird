# Declaration of variables
CC = g++
CC_FLAGS = -Wall -std=c++0x

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
	$(CC) $(OBJECTS) -o $(EXEC) $(LIB) $(DLIBS)
 
# To obtain object files
%.o: %.cpp
	$(CC) $(INC) -c $(CC_FLAGS) $< -o $@
 
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
# Declaration of variables
CC = g++
CC_FLAGS = -Wall

#Headers and Includes
LIB=-L../SFML/SFML-2.4.2-Linux64/lib
INC=-I../SFML/SFML-2.4.2-Linux64/include -I../include
 
# File names
EXEC = run
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
 
# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)
 
# To obtain object files
%.o: %.cpp
	$(CC) $(LIB) $(INC) -c $(CC_FLAGS) $< -o $@
 
# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
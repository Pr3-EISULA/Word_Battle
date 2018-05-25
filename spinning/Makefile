#Copyright Notice:
#The files within this zip file are copyrighted by Lazy Foo' Productions (2004-2014)
#and may not be redistributed without written permission.
INC_PATH = include/
SRC_PATH = src

SOURCES = \
		$(SRC_PATH)/42_texture_streaming.cpp \
	
	

OBJECTS = $(SOURCES:.cpp=.o)


EXECUTABLE = main.exe


#OBJS specifies which files to compile as part of the project


#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -s

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer

#OBJ_NAME specifies the name of our exectuable

.cpp.o: $(SOURCES)
	$(CXX) -I $(INC_PATH) -c $(COMPILE_FLAGS) $^ -o $@
#This is the target that compiles our executable
all : $(OBJECTS)
	$(CC) $(OBJECTS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXECUTABLE)



clean:
	$(RM) $(EXECUTABLE) $(OBJECTS)